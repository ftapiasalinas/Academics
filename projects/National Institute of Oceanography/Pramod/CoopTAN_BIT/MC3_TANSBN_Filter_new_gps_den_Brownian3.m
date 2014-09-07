function [X_hat,P_hat,P_hatb, F, Npart,Qk,fdiverges,simtime,Nreinitt] = MC3_TANSBN_Filter_new_gps_den_Brownian3(Nmin,Nmax,Nextra,Aextra,Max_pos_error,Max_time_error,X0hat,Xt2,X,U,Y,Ns,N,Map,dMap_dx,dMap_dy,adaptssize,adaptnoise,plotmaps,sonarconfig,theta,T,RunNo)
%
% Applies the Rao-blackwellized SIS/R (Sequential Importance Sampling/ Resampling) Particle Filter
% to estimate the position of the vehicle, based on the navigation data
% Francisco Teixeira (NOV-2004)
% Bibliographical refs:
% 1.Arulampalam et al, 2002. A Tutorial on Particle Filters for On-line Nonlinear/Non-Gaussian Bayesian Tracking
%   (IEEE Trans.Siganl Process. vol.50(2), Feb-2002
% 2.Bergman, 1999. Recursive Bayesian Estimation - Navigation and Tracking Applications (PhD thesis - Linkoping Univ.)
%
% Version SISS10_adapt_unifp_reinit : applies 'smoothing' version of formula for calculation of weights
% (Based on MC3_TAN_PF_SISR10_adapt_unifp_reinit.m ); version SISR9_adapt_unifp_reinit : calls calcmdepts3.m which uses statistical model of the error, derived from physical model
%       to compute the likelihood of the measurements


% INPUTS:
%   Nmin = Minimum number of particles used by the filter
%   Nmax = Maximum number of particles used by the filter
%   Nextra = number of extra particles uniformly distributed around the estimated position of vehicle
%   Aextra = matrix to establish the area for uniform distribution of extra particles
%   Max_pos_error : if position error > Max_pos_error during more than Max_time_error (seconds),then filter is considered to diverge
%   Max_time_error = time in seconds used to determine filter divergence
%   X0hat = estimated initial state vector = [x0,y0, bx0, by0]
%   P0hat = estimated initial covariance
%   X = actual state vector along the simulation
%   U = sequence of input vectors [Vu; Vv; psi; r; z] ; psi (rad); r (rad/sec) (z = depth is positive)
%   Y = sequence of measurements: all 3 measurements (ranges and depth) are positive values
%   Ns = Initial number of particles used by the filter
%   TT = total simulation time (seconds)
%   Map = bathymetric map
%   dMap_dx, dMap_dy = gradients of Map relative to x and y
%   adaptssize = 1/0 : control if sample size (num of particles) is adaptative or not
%   adaptnoise = 1/0 : control if added noise is adaptative or not
%   plotmaps = 1/0 : condition all other plots in this script
%   sonarconfig = 1/2/3 (possibly others): geometry of 3rd sonar deployed by the vehicle (see script config_sonarbeams1.m)
%   theta = sonar beam width (degrees)


% OUTPUTS:
%   X_hat = sequence of state point estimates (4x1xN) array
%   P_hat = sequence of covariance estimates (4x4xN) array
%   Npart = sequence of effective and true sample sizes (along the simulation) (2xN array)
%       Npart(1)=Ns ; Npart(2)=Neff ; (Ns can vary along time if addaptssize=1)
%   Qk = Process noise intensity matrix (Q used in CRLB calc)
%   fdiverges = flags filter divergence (based on difference between estimated and true position)
%   simtime = duration of the current simulation
%   itertime = average duration of an iteration during the current simulation
%   Nreinit = number of times the filter re-initialized in the present run

% Notation: -------------------------------------------------------------
% Xkf = Kalman predicted vector x^(t|t-1) ; x^(t|t) is not used in the computations
% Xpf = Particle filter predicted vector x^(t|t-1)
% P_next = covariance matrix P(t|t-1)
% P = P(t|t)
% Xkf_prev = Xkf of the previous iteration
% Xpf_prev = Xpf of the previous iteration
% Xpf_next  = Xpf previewd for the next iteration
% P_prev = P_next of the previous iteration



global invalid_depth
global addnoise_pf

global MAP_RESOLUTION % Altera��o introduzida (FEV/2008) p/ permitir utiliza��o de mapas c/ resolu��es diferentes de 1m (ver Notas G)
global BEACON_POS


% Algorithm constants -----------------------------------------------------

%Ns(2)     = 1000;
%Nextra(2) = 500;
t0 = clock;
P_hatb = zeros(2);
Ns_init=Ns(1);

Max_reinit_time=1; % time in seconds to allow the large set of re-initialized particles to be used (1/T iterarions)
reinitt_time=0;
reinitializedt=0;
Nreinitt=0;

reinitb_time=0;
reinitializedb=0;
Nreinitb=0;
resampleb =0;
resamplet=0;

Min_sum_w=1e-30; % Minimum value of sum of particles' weights to be considered greater than zero
Nst = Ns(1);
Nsb = Ns(2);
Nextrat = Nextra(1);
Nextrab = Nextra(2);
Ntott = Nst + Nextrat; % total num. of particles
Ntotb = Nsb + Nextrab; % total num. of particles


% if Ns < Nmin
%     Ns=Nmin;
% end
% if Ns > Nmax
%     Ns=Nmax;
% end
F=1;
getmovie =1;


ppkde = 0.3; %200/100;
nkde = 0.2;
densityshow =0;
if(~isempty(BEACON_POS))
    %[~, ~, ~, sigmar,~,~] = calc_beaconRange([0;0;0], 0); % std of range measurement
    [~, ~, ~, sigmar,~,~] = calc_vehRange([0;0;0],[0;0;0],1);
	% densityshow =1;
%     if RunNo ==10
%         plotmaps = 10;
%         densityshow = 1;
%     end
else
	% densityshow =0;
	
end


%sigmar= 3*sigmar;


[L C] = size(Map); L=L*MAP_RESOLUTION; C=C*MAP_RESOLUTION;

fdiverges=0;
tdiverges=0;
reinit=0;
fact_reinit=1; % factor applied to Nmax to determine the number of particles to use when re-initialization is applied

factsd=5; %5 (with kstdm=1e-2) factor applied to std.dev. of the statistical measurement model to avoid too spiky likelihoods
factud=0; %.1;  % factor applied to mean of the statistical measurement model
factsd_grad=1; % factor applied as a function of Local gradient

% Changes PK
%factsd=5;
factsdtan=5;
factsd_b =10;%5;% factsd;%3;

hmin=max(max(Map)); % minimum depth in Map
hmax=min(min(Map)); % maximum depth in Map

conf=0.999;   % confidence interval used in the error_ellipse plots

inituniform = 0; % initialize or not particles from uniform distribution
invalid_depth=99999;

%% Not Required PKM
% [rho2,rho3,off_azimsonar2,off_azimsonar3]=config_sonarbeams1(sonarconfig); % configure non-vertical sonar beams

%%

plotparticles=1;
plotellipses=1;
plotdivp=1;       % time divider for ploting particles position only every plotdivv sec
o=1;                % zero-offset for array indexing
%T=0.25;    %
LoadFilterNoises;
P0hat = Sd0*Sd0'; % contonious time
%Qpf_c = diag([std_pnx std_pny]);


pp = 0/100;
% Filter constants
%Tk=fix(TT/T-1);% number of iterations (not possible to update last estimate because there is no input at t=TT)
sx=sqrt((P0hat(1,1) + P0hat(1,1)*pp ).*T);   % sigma_x (std dev of coordinate x) discreate time
sy=sqrt((P0hat(2,2)+ P0hat(2,2)*pp).*T);

% sx = sx + 20*T;
% sy = sy + 20*T;


x0=X0hat(1);
y0=X0hat(2);
Fpf=diag([1 1]);           % Transition matrix
Qpf=diag([std_pnx^2 std_pnx^2]).*T;   % Process noise intensity matrix (of the PF part of state vector)
% sdx=std_pnx;%*sqrt(T);% process noise std dev for translation error in x
% sdy=std_pny;%*sqrt(T);% process noise std dev for translation error in y
addnoise_pf=diag([0.01 0.01]).*sqrt(T);


% if(~isempty(BEACON_POS))
%     addnoise_pfb=diag([.001 .001]).*sqrt(T); %Noise_pf;        % added process noise to spread the particles more
%     AextraBeac = [15 0; 0 15]; %extra particles for Beacon
%     sbx=sqrt((P0hat(3,3)+ P0hat(3,3)*pp ));   % sigma_x (std dev of coordinate x)
%     sby=sqrt((P0hat(4,4)+ P0hat(4,4)*pp ));
%
% %    sbx = sbx + 30*T;
%  %   sby = sby + 30*T;
%
%     bx0=X0hat(3);
%     by0=X0hat(4);
%     Fpfb = diag([1 1]);
%     Qpfb = diag([std_pnbecx^2 std_pnbecy^2]).*T;
%  %   sdbx=sqrt(Qbec(1));% process noise std dev for bx in discrete time
%  %    sdby=sqrt(Qbec(2));% process noise std dev for by in discrete time
% end

% dont use this, this noise is added throught the covaraince matrix
% csd_vx = .1; %                  % standard dev. of Vx in continuos time
% csd_vy = .1; %                  % standard dev. of Vy  in continuos time
% sd_vx=csd_vx*sqrt(T);           % standard dev. of yaw in discrete time model                 ############################
% sd_vy=csd_vy*sqrt(T);           % standard dev. of yaw rate in discrete time model            ############################

Ntt=Nst*0.75; %Nt=Ns*0.25;% Nt=Ns*0.5;  %                    % Threshold for resampling
%Ntb=Nsb*0.75;


%%  ++++++++++++++++++++++++++++++++++++++++++ Filter Initialization +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
% initialize state vector Xpf (particle filter):
unib=1;
unit=1;
if inituniform
    % Draw Ns samples from p(X0hat):
    % Define area for initial position of the vehicle based on the a priori state vector and estimated uncertainty X0hat, P0hat
    % as a uniform distribution in a rectangular area centred on x0,y0 with a (2*sigma_x * 2*sigma_y) area
    %     A=diag([sbx sby]); %
    %     %     Xpf = A * (2*rand(2,Ns) - 1) ; % particles uniformly distributed in the area 2*sx*2*sy, centred at 0,0
    %     if(~isempty(BEACON_POS))
    %         Xpfb = A * (2*rand(2,Nsb) - 1) ; % particles uniformly distributed in the area 2*sx*2*sy, centred at 0,0
    %         %Xpfb = Xpfb + [bx0;by0];
    %         Xpfb(1,:) = Xpfb(1,:) + bx0;
    %         Xpfb(2,:) = Xpfb(2,:) + by0;
    %     end
    A=diag([sx sy]); %
    Xpf = A * (2*rand(2,Nst) - 1) ; % particles uniformly distributed in the area 4*sx*4*sy, centred at 0,0
    %Xpf = Xpf + [x0;y0];
    Xpf(1,:) = Xpf(1,:) + x0;
    Xpf(2,:) = Xpf(2,:) + y0;
    
else
    % Initialize from gaussian distribution
    % Draw Ns samples from p(X0hat):
    % Define area for initial position of the vehicle based on the a priori state vector and estimated uncertainty X0hat, P0hat
    % particles normally distributed with mean [x0;y0] and covar [sx^2 0; 0 sy^2]
    if unit
        A=(3/2).*diag([sx sy]); %
        Xpf = 1.414*A * (2*rand(2,Nst) - 1) ; % particles uniformly distributed in the area 4*sx*4*sy, centred at 0,0
        %Xpf = Xpf + [x0;y0];
        Xpf(1,:) = Xpf(1,:) + x0;
        Xpf(2,:) = Xpf(2,:) + y0;
    else
        Xpf(1,:) = x0 + 1.414*sx* randn(1,Nst);
        Xpf(2,:) = y0 + 1.414*sy* randn(1,Nst);
    end
    
    %     if(~isempty(BEACON_POS))
    %         if unib
    %             %A=diag([L/2  C/2]); %
    %             A=diag([sbx sby]); %
    %             Xpfb(1:2,:) = A * (2*rand(2,Nsb) - 1) ; % particles uniformly distributed in the area L*C, centred at 0,0
    %             Xpfb(1,:) = Xpfb(1,:) + bx0;
    %             Xpfb(2,:) = Xpfb(2,:) + by0; % centre on the Map
    %         else
    %             Xpfb(1,:) = bx0 + 1.414*sbx* randn(1,Nsb);
    %             Xpfb(2,:) = by0 + 1.414*sby* randn(1,Nsb);
    %         end
    %     end
    
end
if Nextra > 0
    % Introduce extra particles based on the a priori state vector X0hat,
    % as a uniform distribution in a rectangular area (2*Max_pos_error/C * 2*Max_pos_error/C) centred on x0,y0:
    
    Xpf(1:2,Nst+1:Ntott) = Aextra * (2*rand(2,Nextrat) - 1) ; % particles uniformly distributed centred at 0,0
    Xpf(1,Nst+1:Ntott) = Xpf(1,Nst+1:Ntott) + x0;
    Xpf(2,Nst+1:Ntott) = Xpf(2,Nst+1:Ntott) + y0; % centre at X_hat
    %     if(~isempty(BEACON_POS))
    %         if unib
    %             Xpfb(1:2,Nsb+1:Ntotb) = A* (2*rand(2,Nextrab) - 1) ; % particles uniformly distributed centred at 0,0
    %             Xpfb(1,Nsb+1:Ntotb) = Xpfb(1,Nsb+1:Ntotb) + bx0;
    %             Xpfb(2,Nsb+1:Ntotb) = Xpfb(2,Nsb+1:Ntotb) + by0; % centre at x0,y0
    %
    %         else
    %             A=diag([sbx sby]); %
    %             Xpfb(1:2,Nsb+1:Ntotb) =  A* (2*rand(2,Nextrab) - 1) ; % particles uniformly distributed centred at 0,0  AextraBeac
    %             Xpfb(1,Nsb+1:Ntotb) = Xpfb(1,Nsb+1:Ntotb) + bx0;
    %             Xpfb(2,Nsb+1:Ntotb) = Xpfb(2,Nsb+1:Ntotb) + by0; % centre at x0,y0
    %         end
    %     end
end

% if(~isempty(BEACON_POS))
% Xpf_prevb=Xpfb;
% Xpf_noiseb=sqrtm(Qpfb) + addnoise_pfb; % std dev ofthe process noise
%
% end
% Predict the states for t=1:------------------------------------------------------------------------------
k=o; % time t=0
% Predict each of the Ns states independently generating the new set of particles
% Notice that the covariance and kalman gain are the same for all i particles: i=1:Ns
% Only the previewd state x^(t+1|t) and the previewd covariance P(t+1|t) of the previous iteration are maintained
Xpf_prev=Xpf;
Xpf_noise=sqrtm(Qpf)   + addnoise_pf; % std dev ofthe process noise


% Predict  states:
GU=GuU_gps(T.*U(:,k),0,0,Nst); % Make these sd to zero not to add any noise *pkmnew

% if(~isempty(BEACON_POS))
%     Xpf_nextb = Fpf*Xpfb(:,1:Nsb) + Xpf_noiseb*randn(2,Nsb);  % Particle predicted states
%     u_Xpfb    = Fpfb*Xpf_prevb(:,1:Nsb); % expected value of Xpf for calculation of p
% end
Xpf_next = Fpf*Xpf(:,1:Nst) + GU + Xpf_noise*randn(2,Nst);  % Particle predicted states
u_Xpf    = Fpf*Xpf_prev(:,1:Nst) + GU; % expected value of Xpf for calculation of p

% w(1:Ns)=1/Ns; % assign each particle the weight 1/Ns
wt(1:Ntott)=1/Ntott; % assign each particle the weight 1/Ntot
% if(~isempty(BEACON_POS))
% wb(1:Ntotb)=1/Ntotb; % assign each particle the weight 1/Ntot
% end

% variables recorded for error analysis
Npart(1,o)=Nst; % initial value of Ns
Npart(2,o)=1/sum(wt.^2); % initial value of Neff

[X_hat(1:2,o) P_hat(:,:,o)]   =  point_estimates(Xpf,wt); % Initial estimated position of vehicle
% if(~isempty(BEACON_POS))
% [X_hat(3:4,o) P_hatb(:,:,o)]  =  point_estimates(Xpfb,wb); % Initial estimated position of beacon
% end
distime = 0;
%close all;
figpos =[285   70   814   612];
tht = 0:pi/6:2*pi;
circ =1;
% if(~isempty(BEACON_POS))
% w4   = ones(1,length(Xpfb));
% end

if plotmaps
    % Draw map and location of vehicle
    % contour(Map,[-55,-50,-45,-40,-35,-30,-25,-20])
    %     if getmovie
    %         F(N) = struct('cdata',[],'colormap',[]);
    %         fcounter = 1;
    %     end
    fig1=figure; hold on;
    contour(Map,20);%axis equal;
    ax1 = get(fig1,'CurrentAxes');
    xlim = get(ax1,'XLim');
    ylim = get(ax1,'YLim');
    plot(X(2,:)/MAP_RESOLUTION, X(1,:)/MAP_RESOLUTION,'-.r'); % Plot intial position of vehicle
    %axis([0 800 0 400])
    set(fig1,'Position',figpos);
    grid on; title('Trajectory of the Vehicle');
    text(170,355,'T: ');
    
    
    distime = 0*T;
    distimeh = text(185,355,[num2str(distime) 's']);
    
    
    %distimeh= title(['Trajectory of the Vehicle' '     Time:' num2str(distime)]);
    
    if MAP_RESOLUTION==1
        xlabel('Easting (meters)')
        ylabel('Northing (meters)')
    else
        xlabel(['Easting', ' (meters x ' , num2str(MAP_RESOLUTION), ')'])
        ylabel(['Northing',' x ',' (meters x ' , num2str(MAP_RESOLUTION), ')'])
    end
    %fig1=open('djcastroctr2.fig');
    hold on
    
    
    
    if plotparticles
        %g3=plot(Xpf(2,:)/MAP_RESOLUTION,Xpf(1,:)/MAP_RESOLUTION,'.k');
        g3 = scatter(Xpf(2,:),Xpf(1,:),5, wt,'o','Filled'), grid on
        set(g3,'EraseMode','xor');
        
        %         hc = colorbar;
        %         set(hc,'YTickMode','manual')
        %         set(hc,'YTickLabelMode','manual')
        %         set(hc,'YLim',[0 0.8]);
        
        hc=colorbar;
        %         yt = 0:.2:.8;
        %         cu = unique(yt);
        %         set(hc,'ytick',yt,'yticklabel',cu);
        set(gca, 'CLim', [0, 0.002]);
        
    end
    % plot uncertainty ellipse
    if plotellipses
        errh=error_ellipse2D(P_hat(:,:,o)/MAP_RESOLUTION^2,X_hat(1:2,o)/MAP_RESOLUTION,conf,1);
        
    end
    if(~isempty(BEACON_POS) && plotmaps)
        % if(Xt2(2,o)~=-1)
        gbec=plot(Xt2(2,o),Xt2(1,o),'vb', 'MarkerEdgeColor','k',...
            'MarkerFaceColor','b',...
            'MarkerSize',8); % Becon position of the vehicle
        %   end
        
        %    set(gbec,'EraseMode','none');
        g1=plot(X(2,o)/MAP_RESOLUTION,X(1,o)/MAP_RESOLUTION,'*r'); % Plot intial position of vehicle
        %   set(g1,'EraseMode','xor');
        g2=plot(X_hat(2,o)/MAP_RESOLUTION,X_hat(1,o)/MAP_RESOLUTION,'or'); % Plot estimated position of vehicle
        %  set(g2,'EraseMode','xor');
        
        % set(g2b,'EraseMode','xor');
        legend([g1 g2 gbec],'actual vehicle position','estimated vehicle position','actual beacon position','Location','BestOutside');
        if circ %&& Y(2,o)~=-1
            xp = X(1,o) + Y(2,o).*cos(tht);
            yp = X(2,o) + Y(2,o).*sin(tht);
            gcir=plot(yp,xp,'-r','LineWidth',2); % Plot estimated position of vehicle
            set(gcir,'EraseMode','xor');
        end
    else
        g1=plot(X(2,o)/MAP_RESOLUTION,X(1,o)/MAP_RESOLUTION,'*r'); % Plot intial position of vehicle
        set(g1,'EraseMode','xor');
        g2=plot(X_hat(2,o)/MAP_RESOLUTION,X_hat(1,o)/MAP_RESOLUTION,'or'); % Plot estimated position of vehicle
        set(g2,'EraseMode','xor');
        legend([g1 g2],'actual vehicle position','estimated vehicle position','Location','BestOutside');
        
    end
    % set(ax1,'XTick',[50:50:max(xlim)])
    % set(ax1,'YTick',[50:50:max(ylim)]);
    % axis equal
    % axis([xlim ylim])
    %contour(Map,20);%axis equal;
    %  pause;
    
end


Xpf=Xpf_next;
z20 = 0;
sd4 = 0.15;
ud4 = 0;

% if(~isempty(BEACON_POS))
% end
if Nextra > 0
    % Introduce extra particles based on the a priori state vector X0hat,
    % as a uniform distribution in a rectangular area (2*Max_pos_error/C * 2*Max_pos_error/C) centred on x0,y0:
    Xpf(1:2,Nst+1:Ntott) = Aextra * (2*rand(2,Nextrat) - 1) ; % particles uniformly distributed centred at 0,0
    Xpf(1,Nst+1:Ntott) = Xpf(1,Nst+1:Ntott) + x0; Xpf(2,Nst+1:Ntott) = Xpf(2,Nst+1:Ntott) + y0; % centre at x0,y0
    u_Xpf(:,Nst+1:Ntott)= Fpf*Xpf_prev(:,Nst+1:Ntott) + [GuU_gps(T.*U(:,k),0,0,Nextrat)];
end

if(~isempty(BEACON_POS))
    xcc = min(Xpf(1,:)) + (max(Xpf(1,:))-min(Xpf(1,:)))/2;
    ycc = min(Xpf(2,:)) + (max(Xpf(2,:))-min(Xpf(2,:)))/2;
    rad = norm([xcc;ycc]-[max(Xpf(1,:));max(Xpf(2,:))])
    if Y(2,k)~=-1
        r0 = Y(2,k);%
    else
        firstdata = find(Y(2,:)~=-1);
        r0 = Y(2,firstdata(1));
    end
    drr = 3*sigmar + rad; % Ring diameter
    
    a  = r0 - drr;
    br = r0 + drr;
    
    r  = a + (br-a).*rand(1,Ntotb);
    th = 2*pi*rand(1,Ntotb);
    %minmaxr  = [min(r) ;max(r)];
    %minmaxth = [min(th);max(th)];
    %Xpfb(1,:) = xcc + r.*cos(th);
    %Xpfb(2,:) = ycc + r.*sin(th);
    
    if plotparticles && plotmaps
        %   g3b = scatter(Xpfb(2,:),Xpfb(1,:),5, wt,'o','Filled'), grid on
        %   set(g3b,'EraseMode','xor');
        set(g3, 'XData',Xpf(2,:), 'YData',Xpf(1,:));
    end
    
    nkdr  = 0.5;
    nkdth = 3/r0;  % insures grid of ~0.5 x 3 m
    [RR,TH]=meshgrid(min(r):nkdr:max(r),min(th):nkdth:max(th));
    [Xd,Yd] = pol2cart(TH,RR);
    Xd_ = Xd + xcc;
    Yd_ = Yd + ycc;
    
    %[Xd, Yd, density] = densityfn_polar(Xpf,xcc,ycc,minmaxr,minmaxth,nkdr,nkdth,Y(2,k),wt,sigmar*factsd_b);
    
    %     if (densityshow && plotmaps)
    %
    %         [~, densurfb] = contour(Yd,Xd,density,20);
    %         set(densurfb,'EraseMode','xor');
    %         maxc = max(max(density));caxis([0 maxc]);
    %         drawnow;
    %     end
end
% Alts = Map_valid2(Map,Xd,Yd);  % measure in the vertical of the sensor
% f2t_Xpf=-(Alts + z20); % ranges = -mapped_depths - vehicle_depth
% w2t=likely(Y(3,k),f2t_Xpf,ud4*factud,sd4.*factsdtan);
% w2 = density.*w2t;
% [rw2,cw2] = size(w2);
% Xpfb2 = zeros(2,rw2*cw2);
% w2a   = ones(1,rw2*cw2);
%
% in=1;
% for ir=1:rw2 % unroll the grid
%     for ic = 1:cw2
%         Xpfb2(1,in) = Xd(ir,ic);
%         Xpfb2(2,in) = Yd(ir,ic);
%         w2a(in)     = w2(ir,ic);
%         in=in+1;
%     end
% end
% if (densityshow && plotmaps)
%
%     set(densurfb,'XData',Yd,'YData', Xd,'Zdata', w2);
%     maxc = max(max(w2));caxis([0 maxc]);
%
% end


%[wc, Xd, Yd, density] = densityfn(Xpfb2,Xpf,nkde,ppkde,Y(2,k),w2a,sigmar*factsd_b); % For vehicle update

% wc(1:Ntott)=wc./sum(wc);

% pind=resample3(wc,Ntott);                    % resample Ntot particles
% Xpf(1:2,:)=Xpf(1:2,pind);        % resampled set of particles
if plotmaps
clk = fix(clock);
fldrname = sprintf('FramesRunNo_%.0f_%s-%02.0f-%02.0f-%02.0f',RunNo,date,clk(4:end));
eval(sprintf('!mkdir %s',fldrname));
curr_path =cd;
FrameFolder = [curr_path '\' fldrname '\'];
end

if (densityshow && plotmaps &&  ~isempty(BEACON_POS))
    Alts = Map_valid2(Map,Xd_,Yd_);  % measure in the vertical of the sensor
    f2t_Xpf=-(Alts + z20); % ranges = -mapped_depths - vehicle_depth
    w2t=likely(Y(3,k),f2t_Xpf,ud4*factud,sd4.*factsdtan);
    w2 = w2t;
    [rw2,cw2] = size(w2);
    Xpfb2 = zeros(2,rw2*cw2);
    w2a   = ones(1,rw2*cw2);
    NN=rw2*cw2;
    Xpfb2(1,:) = reshape(Xd',1,NN);
    Xpfb2(2,:) = reshape(Yd',1,NN);
    w2a(1,:)   = reshape(w2',1,NN);
    
    MIN_XY1 = [min(Xpf(1,:)),min(Xpf(2,:))];
    MAX_XY1 = [max(Xpf(1,:)),max(Xpf(2,:))];
    
    MIN_XY =   MIN_XY1 - (MAX_XY1-MIN_XY1).*ppkde;
    MAX_XY =   MAX_XY1 + (MAX_XY1-MIN_XY1).*ppkde;
    [Xd,Yd]=meshgrid(MIN_XY(1):nkde:MAX_XY(1),MIN_XY(2):nkde:MAX_XY(2));
    density = zeros(size(Xd));
    
    
    
    
    %[wc, Xd, Yd, density] = densityfn(Xpfb2,Xpf,nkde,ppkde,Y(2,k),w2a,sigmar*factsd_b); % For vehicle update
    %[wc, Xd, Yd, density] = densityfn_LB(Xpfb2,Xpf,nkde,ppkde,Y(2,k),w2a,sigmar*factsd_b,2); % For vehicle update
    [~, densurft] = contour(Yd,Xd,density,20);
    set(densurft,'EraseMode','xor');
    maxc = max(max(density));caxis([0 maxc]);
    drawnow;
    
    set(ax1,'XTick',[50:50:max(xlim)])
    set(ax1,'YTick',[50:50:max(ylim)]);
    axis equal
    axis([xlim ylim])
    if(~isempty(BEACON_POS))
        % set(g3b,'XData',Xpfb(2,:),'YData',Xpfb(1,:),'CData',wc);
        set(g3, 'XData',Xpf(2,:), 'YData',Xpf(1,:));
    end
    drawnow;
    if getmovie
        %F(fcounter) = getframe;
        %fcounter = fcounter +1;
        %jpgFileName = sprintf('Frame_%06d.jpg',o);
		jpgFileName = fullfile(FrameFolder, sprintf('Frame_%06d.jpg',o));
        save2jpg(jpgFileName,fig1,200);
        close(fig1);
    end
    %set(densurf,'XData',Yd,'YData', Xd,'Zdata', density);
    %maxc = max(max(density));caxis([0 maxc]);
    %drawnow
else
    if plotmaps
        set(ax1,'XTick',[50:50:max(xlim)])
        set(ax1,'YTick',[50:50:max(ylim)]);
        axis equal
        axis([xlim ylim])
        if getmovie
            %F(fcounter) = getframe;
            %fcounter = fcounter +1;
            %jpgFileName = sprintf('Frame_%06d.jpg',o);
			jpgFileName = fullfile(FrameFolder, sprintf('Frame_%06d.jpg',o));
            save2jpg(jpgFileName,fig1,200);
            close(fig1);
        end
        Yd=0;Xd=0;density=0;
    end
end

Mapplot = Map;
Map(1,1)=invalid_depth; % Set flag value in the Map. Do this ONLY after drawing (contour) the map and after obtaining hmin & hmax !!

Qk =  Qpf;

%  +++++++++++++++++++++++++++++++++++++++++ END of Filter Initialization ++++++++++++++++++++++++++++++++++++++++++++++++++


%%  ++++++++++++++++++++++++++++++++++++++++++++++ MAIN LOOP ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Locgrad = 0;
factsd_grad=0.5.*exp((2-Locgrad)/0.25);


simtime=etime(clock,t0);
fidfile = fopen('debug_pf2.txt','w');
fprintf(fidfile,' Initialization over in : %.1f ..\n',simtime);
fprintf(' Initialization over in : %.1f ..\n',simtime);
t0=clock;
t1 =t0;
meas_available =0;
for k=1+o:N
    
    if(~isempty(BEACON_POS))
        if(Y(2,k)~=-1 && Y(3,k)~=-1)
            %tic,
            xcc = min(Xpf(1,:)) + (max(Xpf(1,:))-min(Xpf(1,:)))/2;
            ycc = min(Xpf(2,:)) + (max(Xpf(2,:))-min(Xpf(2,:)))/2;
            rad = norm([xcc;ycc]-[max(Xpf(1,:));max(Xpf(2,:))]);
            r0 = Y(2,k);%
            drr = 3*sigmar + rad;
            a  = r0 - drr;
            br = r0 + drr;
            %r  = a + (br-a).*rand(1,Ntotb);
            %th = 2*pi*rand(1,Ntotb);
            % minmaxr  = [min(r) ;max(r)];
            % minmaxth = [min(th);max(th)];
            %Xpfb(1,:) = xcc + r.*cos(th);
            %Xpfb(2,:) = ycc + r.*sin(th);
            nkdr  = 0.5;
            nkdth = 0.5/Y(2,k);  % insures grid of ~.5 x .5 at 300 m range
            
            
            
            [RR,TH]=meshgrid(a:nkdr:br,0:nkdth:2*pi);
            [Xd,Yd] = pol2cart(TH,RR);
            Xd_ = Xd + xcc;
            Yd_ = Yd + ycc;
            %[Xd, Yd, density] = densityfn_polar(Xpf,xcc,ycc,minmaxr,minmaxth,nkdr,nkdth,Y(2,k),wt,sigmar*factsd_b);
            
            Alts = Map_valid2(Map,Xd_,Yd_);  % measure in the vertical of the sensor
            f2t_Xpf=(Alts - z20); % ranges = -mapped_depths - vehicle_depth
            w2t=likely(Y(3,k),f2t_Xpf,ud4*factud,sd4.*factsdtan);
            %w2 = density.*w2t;
            w2 = w2t;
            
            if densityshow && plotmaps && 0
                set(densurfb,'XData',Yd,'YData', Xd,'Zdata', w2);
                maxc = max(max(w2));caxis([0 maxc]);
                drawnow;
            end
            [rw2,cw2] = size(w2);
            Xpfb2 = zeros(2,rw2*cw2);
            w2a   = ones(1,rw2*cw2);
            NN=rw2*cw2;
            Xpfb2(1,:) = reshape(Xd_',1,NN);
            Xpfb2(2,:) = reshape(Yd_',1,NN);
            w2a(1,:)   = reshape(w2',1,NN);
            %             in=1;
            %             for ir=1:rw2
            %                 for ic = 1:cw2
            %                     Xpfb2(1,in) = Xd(ir,ic);
            %                     Xpfb2(2,in) = Yd(ir,ic);
            %                     w2a(in)     = w2(ir,ic);
            %                     in=in+1;
            %                 end
            %             end
            
            w2a = w2a./sum(w2a);% Normalize the weight before feeding to density
            %[wc, Xd, Yd, density] = densityfn(Xpfb2,Xpf,nkde,ppkde,Y(2,k),w2a,sigmar*factsd_b); % For vehicle update
            [wc, Xd, Yd, density] = densityfn_LB(Xpfb2,Xpf,nkde,ppkde,Y(2,k),w2a,sigmar*factsd_b,densityshow); % For vehicle update
            %b Normalize wc
            wc = wc./sum(wc);
            meas_available =1;
            %  denstime=toc
            %  disp('Paused'); pause
            if densityshow && plotmaps && 0
                set(densurft,'XData',Yd,'YData', Xd,'Zdata', density);
                maxc = max(max(density));caxis([0 maxc]);
                drawnow;
            end
            
        else
            wc=1;
            
        end
    else
        wc = 1;
        
    end
    
    
    %%
    if(Y(1,k)~=-1)
        zmin = abs(hmin + U(5,k));
        zmax = abs(hmax + U(5,k));
        [f1_Xpf,~,ud1,sd1]=calc_mdepths3(Map,dMap_dx, dMap_dy, Xpf(1:2,:), U(5,k), zmin, zmax, U(3,k), pi/2, 1,theta);
        w1=likely(Y(1,k),f1_Xpf,ud1*factud,sd1.*factsdtan);
        % [~,I1] = max(w1);
        %  res_tan(k) =  Y(1,k)- f1_Xpf(I1);
    else
        w1=1;
    end
    
    if(Y(1,k)~=-1)
        pt=exp_norm(Xpf,u_Xpf,Qpf*factsd*factsd_grad);
        % pb=exp_norm(Xpfb,u_Xpfb,Qpfb*factsd*factsd_grad);
    else
        pt=1;
    end
    
    wt=wt.*w1.*wc.*pt;%.*w3.*pt;%.*pb.*w4; % rr  % See expression for the Smooth Kernel PF;  Eq.(7.6) PhD thesis
    %  if(~isempty(BEACON_POS))
    %   wb=wb.*w4;%.*pb;%.*pt.*w1;
    %  end
    
    %  ++++++++++++++++++++++++++++++++++++++++++ Normalize Weights +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    sum_wt = sum(wt);
    if sum_wt < Min_sum_w
        wt(1:Ntott) = 1/Ntott; % w = 1/lenght(w); % sometimes the weights go all to zero
        disp(['WARNING: all the particles collapsed to nearly zero at time ' num2str(k)])
        reinitt=1;
        Nreinitt = Nreinitt + 1;
        reinitt_time=0;
    else
        wt = wt/sum_wt;
        reinitt=0;
        reinitt_time = reinitt_time + T; %
    end
    %% +++++
    
    if reinitt
        % Re-Initialize a much larger set of particles over the whole map ----------------------------------------------------
        reinitializedt=1;
        % Ntot=Nmax*fact_reinit;
        % Ns=Ntot-Nextra; % necessary for compatibility with Prediction code that calculates Xpf_next
        % Draw Ntot samples uniformly distributed in a rectangular area
        A=diag([C/2  L/2]); %
        Xpft = A * (2*rand(2,Ntott) - 1) ; % particles uniformly distributed in the area L*C, centred at 0,0
        Xpf(1,:) = Xpft(1,:) + C/2;
        Xpf(2,:) = Xpft(2,:) + L/2; % centre on the Map
        
        
        % Re-compute and re-normalize weights
        %  ++++++++++++++++++++++++++++++++++++++++++ Compute Weights +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        %%
        
        [f1_Xpf,depths1,ud1,sd1]=...
            calc_mdepths3(Map,dMap_dx, dMap_dy, Xpf(1:2,:), U(5,k), zmin, zmax, U(3,k), pi/2, 1,theta); % f1_Xpf = ranges at the vertical of sensor (rho2=pi/2)
        
        w1=likely(Y(1,k),f1_Xpf,ud1*factud,sd1*factsd);
        
        %******************************************************************************************************************************************************
        
        if(~isempty(BEACON_POS))
            if(Y(2,k)~=-1 && Y(3,k)~=-1)
                
                xcc = min(Xpf(1,:)) + (max(Xpf(1,:))-min(Xpf(1,:)))/2;
                ycc = min(Xpf(2,:)) + (max(Xpf(2,:))-min(Xpf(2,:)))/2;
                rad = norm([xcc;ycc]-[max(Xpf(1,:));max(Xpf(2,:))])
                r0 = Y(2,k);%
                drr = 3*sigmar + rad;
                a  = r0 - drr;
                br = r0 + drr;
                r  = a + (br-a).*rand(1,Ntotb);
                th = 2*pi*rand(1,Ntotb);
                %minmaxr  = [min(r) ;max(r)];
                %minmaxth = [min(th);max(th)];
                %   Xpfb(1,:) = xcc + r.*cos(th);
                %   Xpfb(2,:) = ycc + r.*sin(th);
                [RR,TH]=meshgrid(a:nkdr:br,0:nkdth:2*pi);
                [Xd,Yd] = pol2cart(TH,RR);
                Xd_ = Xd + xcc;
                Yd_ = Yd + ycc;
                %[Xd, Yd, density] = densityfn_polar(Xpf,xcc,ycc,minmaxr,minmaxth,nkdr,nkdth,Y(2,k),w1,sigmar*factsd_b);
                
                Alts = Map_valid2(Map,Xd_,Yd_);  % measure in the vertical of the sensor
                f2t_Xpf=(Alts - z20); % ranges = -mapped_depths - vehicle_depth
                w2t=likely(Y(3,k),f2t_Xpf,ud4*factud,sd4.*factsdtan);
                w2 = density.*w2t;
                
                if densityshow && plotmaps
                    set(densurfb,'XData',Yd_,'YData', Xd_,'Zdata', w2);
                    maxc = max(max(w2));caxis([0 maxc]);
                    drawnow;
                end
                [rw2,cw2] = size(w2);
                Xpfb2 = zeros(2,rw2*cw2);
                w2a   = ones(1,rw2*cw2);
                NN=rw2*cw2;
                Xpfb2(1,:) = reshape(Xd_',1,NN);
                Xpfb2(2,:) = reshape(Yd_',1,NN);
                w2a(1,:)   = reshape(w2',1,NN);
                %                 in=1;
                %                 for ir=1:rw2
                %                     for ic = 1:cw2
                %                         Xpfb2(1,in) = Xd(ir,ic);
                %                         Xpfb2(2,in) = Yd(ir,ic);
                %                         w2a(in)     = w2(ir,ic);
                %                         in=in+1;
                %                     end
                %                 end
                
                w2a = w2a./sum(w2a); %Normalize weights before feeding density
                [wc, Xd, Yd, density] = densityfn_LB(Xpfb2,Xpf,nkde,ppkde,Y(2,k),w2a,sigmar*factsd_b,densityshow); % For vehicle update
				%b Normalize wc
				wc = wc./sum(wc);                
                
                if densityshow && plotmaps && 0
                    set(densurft,'XData',Yd,'YData', Xd,'Zdata', density);
                    maxc = max(max(density));caxis([0 maxc]);
                    drawnow;
                end
                
            else
                wc=1;
                
            end
        else
            wc = 1;
            
        end
        
        %******************************************************************************************************************************************************
        
        
        
        
        
        
        wt = wc;
        sum_wt = sum(wt);
        if sum_wt < Min_sum_w
            wt(1:Ntott) = 1/Ntott; % w = 1/lenght(w); % sometimes the weights go all to zero
            disp(['RE-INITIALIZATION WARNING: all the particles maintain near zero weight at time ' num2str(k)])
        else
            wt = wt/sum_wt;
        end
    end
    
    %  ++++++++++++++++++++++++++++++++++++++++++ Compute point estimates++++++++++++++++++++++++++++++++++++++++++++++++++++
    [X_hat(1:2,k) P_hat(:,:,k)]=point_estimates(Xpf(1:2,:),wt);
    
    
    % Draw  spatial distribution of particles
    if plotmaps
        if(~mod(k,plotmaps) || k==2 || meas_available)
            %if meas_available
            %    meas_available;
            %end
			if densityshow
            Fr = save_plots3(Mapplot, X, Xt2, X_hat, Y,P_hat, Xpf(:,1:Nst), wt(1:Nst), Xd,Yd,density, Xd_,Yd_,Alts,MAP_RESOLUTION, BEACON_POS, plotparticles, plotellipses,conf, errh, k, circ, tht,getmovie,figpos,T,meas_available,FrameFolder);
			else
			 Fr = save_plots3(Mapplot, X, Xt2, X_hat, Y,P_hat, Xpf(:,1:Nst), wt(1:Nst), 0,0,0, 0,0,0,MAP_RESOLUTION, BEACON_POS, plotparticles, plotellipses,conf, errh, k, circ, tht,getmovie,figpos,T,meas_available,FrameFolder);
			end
            
            %[Fr,fig1,densurft] = save_plots_ret_handle(Mapplot, X, Xt2, X_hat, Y,P_hat, Xpf(:,1:Nst), wt(1:Nst), Xd,Yd,density, MAP_RESOLUTION, BEACON_POS, plotparticles, plotellipses,conf, errh, k, circ, tht,getmovie,figpos,T,meas_available);
            meas_available=0;
            clear functions;
            %             if getmovie
            %                 %F(fcounter) = Fr;
            %                 %fcounter = fcounter +1;
            %                 fprintf(fidfile,'%d,',k);
            %             end
            
            if ~mod(k,10) && 0
                e30t =  etime(clock,t1);
                fprintf(fidfile,' %2.0f of %5.0f iterations over.. Time taken :  %12.8f\n',k, N,e30t);
                t1=clock;
            end
        end
    else
        if ~mod(k,10)
            e30t =  etime(clock,t1);
            fprintf(' %2.0f of %5.0f iterations over.. Time taken :  %12.8f\n',k, N,e30t);
            t1=clock;
        end
    end
    
    % Compute scalar position error and detect filter divergence based on error magnitude:
    % ATTENTION: this is possible ONLY in simulations, NOT in real tests
    pos_error= sqrt((X(2,k)-X_hat(2,k))^2 + (X(1,k)-X_hat(1,k))^2);
    if pos_error > Max_pos_error
        tdiverges=tdiverges+T;
        if tdiverges > Max_time_error
            fdiverges=1;
        end
    else
        tdiverges=0; % reset diverging timming
    end
    
    %  ++++++++++++++++++++++++++++++++++++++++++ Compute Effective Sample Size +++++++++++++++++++++++++++++++++++++++++++++
    Nefft=1/sum(wt.^2);
    Npart(2,k)=Nefft;
    if (Nefft < Ntt) | (Nefft<=1)
        resamplet=1;
    else
        resamplet=0;
    end
    
    %%
    
    %  +++++++++++++++++++++++++++++++++++++++++++++++ Adapt Sample Size ++++++++++++++++++++++++++++++++++++++++++++++++++
    if adaptssize & ~reinitt &  (reinitt_time > Max_reinit_time) %~fdiverges % (pos_error > Max_pos_error)
        if Nefft~=0
            N_prev=Nst;
            Nsbt=Nmin+100*fix(100/Nefft); % Adapt sample size for next iteration
            if Nst > Nmax
                Ns=Nmax;
            end
            if N_prev~=Ns
                resamplet=1;
            end
        end
        reinitializedt=0; % reset flag of re-initialization
        Ntott = Nst + Nextrat;
    else
        if ~adaptssize & reinitializedt & (reinitt_time == Max_reinit_time)
            Nst=Ns_init; % reset number of particles to initial values
            Ntott = Nst + Nextrat;
            reinitializedt=0; % reset flag of re-initialization
            resamplet=1;
        end
        
    end
    Npart(1,k)=Ntott;
    
    
    %    Npart(1,k)=Ntot;
    
    %  ++++++++++++++++++++++++++++++++++++++++++ Resample ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if resamplet
        pind=resample3(wt,Ntott);                    % resample Ntot particles
        %pind = randsample(Ntot,Ntot,true,wt);
        Xpf(1:2,:)=Xpf(1:2,pind);        % resampled set of particles
        wt(1:Ntott)=1/Ntott; wt=wt(1:Ntott); % reset weights
    end
    
    
    %  ++++++++++++++++++++++++++++++++++++++++++ Prediction +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    % Predict each of the Ns states independently, generating the new set of particles
    % Notice that the covariance and kalman gain are the same for all i particles: i=1:Ns
    % Only the previewd state x^(t+1|t) and the previewd covariance P(t+1|t) of the previous iteration are maintained
    
    %GU=GuU(U(:,k),sd_psi,sd_psirate,Ns);
    GU=GuU_gps(T.*U(:,k),0,0,Nst);
    %GU =T.* U(:,k);
    Xpf_noise=sqrtm(Qpf)+ addnoise_pf; % rr
    
    %     if(~isempty(BEACON_POS))
    %         Xpf_noiseb=sqrtm(Qpfb)+ addnoise_pfb; % rr
    %         Xpf_nextb(:,1:Nsb) = Fpfb*Xpfb(:,1:Nsb) + Xpf_noiseb*randn(2,Nsb);  % Particle predicted states
    %         Xpf_prevb=Xpfb;
    %         Xpfb=Xpf_nextb(:,1:Nsb); % Notice that length(Xkf_next) in the previous iter. could be larger
    %          if length(u_Xpfb)>Ntotb
    %             % Notice that length(u_Xpf) in the previous iter. could be larger and the following operations would fail
    %              u_Xpfb=u_Xpfb(:,1:Ntotb);
    %         end
    %     end
    
    Xpf_next(:,1:Nst) = Fpf*Xpf(:,1:Nst) + GU + Xpf_noise*randn(2,Nst);  % Particle predicted states
    Xpf_prev=Xpf;
    Xpf=Xpf_next(:,1:Nst); % Notice that length(Xkf_next) in the previous iter. could be larger
    % Introduce extra particles based on the a priori state vector X_hat
    % as a uniform distribution in a rectangular area centred on X_hat with a (Max_pos_error * Max_pos_error) area
    if length(u_Xpf)>Ntott
        % Notice that length(u_Xpf) in the previous iter. could be larger and the following operations would fail
        u_Xpf=u_Xpf(:,1:Ntott);
    end
    if Nextra > 0
        
        Xpf(1:2,Nst+1:Ntott) = Aextra * (2*rand(2,Nextrat) - 1) ; % particles uniformly distributed centred at 0,0
        Xpf(1,Nst+1:Ntott) = Xpf(1,Nst+1:Ntott) + X_hat(1,k);
        Xpf(2,Nst+1:Ntott) = Xpf(2,Nst+1:Ntott) + X_hat(2,k); % centre at X_hat
        %         if(~isempty(BEACON_POS))
        %             Xpfb(1:2,Nsb+1:Ntotb) = AextraBeac * (2*rand(2,Nextrab) - 1) ; % particles uniformly distributed centred at 0,0
        %             Xpfb(1,Nsb+1:Ntotb) = Xpfb(1,Nsb+1:Ntotb) + X_hat(3,k);
        %             Xpfb(2,Nsb+1:Ntotb) = Xpfb(2,Nsb+1:Ntotb) + X_hat(4,k); % centre at x0,y0
        %             u_Xpfb(:,Nsb+1:Ntotb)=Fpfb*Xpf_prevb(:,Nsb+1:Ntotb); % expected value for extra particles (uniformly distributed around the vehicle)
        %         end
        u_Xpf(:,Nst+1:Ntott)=Fpf*Xpf_prev(:,Nst+1:Ntott) + GuU_gps(T.*U(:,k),0,0,Nextrat); % expected value for extra particles (uniformly distributed around the vehicle)
        
        
    end
    % Cycle to next iteration
    % Locgrad_est=sqrt((Map_valid2(dMap_dx,X_hat(1,k),X_hat(2,k)))^2 + (Map_valid2(dMap_dy,X_hat(1,k),X_hat(2,k)))^2); % scalar measure of actual local gradient at estimated vehicle position
    % Local gradient may be used to add noise as function of gradient, but
    % it is not used right now
    
    %     if(~isempty(BEACON_POS))
    %         u_Xpfb(:,1:Nsb) = Fpfb*Xpf_prevb(:,1:Nsb);
    %     end
    u_Xpf(:,1:Nst) = Fpf*Xpf_prev(:,1:Nst) + GU; % rr
    
end
simtime=etime(clock,t0);
disp(['Simulation total time (sec): ' num2str(simtime)])
% if plotmaps
%     close(fig1)
% end
if pos_error < (Max_pos_error / 2)
    tdiverges=0; % if final estimation error is not large, filter is considered to converge
end

if  ~getmovie
    F=-1;
end
fclose(fidfile);