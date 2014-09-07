clear;
% The blck medusa is navigating and red medusa is acting as moving.

load black_Rectangle_inp_meas_data
load expomap_used_movie;
refX = 491772.832289244 ;
refY = 4290573.90126041 ;

%load working_data_Trajectory_A;
%load expomapNosmooth;%;%expomap;
%load expo_surfer_smooth;
%load surfer_smooth_map;
% load expomapNoOutlier;
% load smooth Map
if (exist('BatDJC400x800','var'))
    smoothmap=1;genmap = 0;
    azores = 1;
    exposite = 0;
    if genmap
        smoothmap = 0;
        [X,Y] = meshgrid(0:800, 0:400);
        BatDJC400x800 = -50 + (50-20)/320000.*X.*Y; % ramp
    end
    if smoothmap
        BatDJC400x800 = mapsmootherDct(BatDJC400x800, 98.5); %95%mapsmoother(BatDJC400x800,.05, 1);
        % BatDJC400x800 = mapsmootherDct(BatDJC400x800, 99.5); %95%mapsmoother(BatDJC400x800,.05, 1);
        % BatDJC400x800(300:350,200:650) = mapsmootherDct(BatDJC400x800(300:350,200:650), 99);
        % BatDJC400x800(300:350,200:650) = mapsmootherDct(BatDJC400x800(300:350,200:650), 99.5);
        [dMap_dx,dMap_dy] = gradient(BatDJC400x800);
    end
else
    BatDJC400x800 = expodata_r1;
    [dMap_dx,dMap_dy] = gradient(BatDJC400x800);
    %clear BatMatrixExpo;
    azores = 0;
    exposite = 1;
end
theta = 10;
theta_beam = theta;

surffig = 0;
if surffig
    figure, surf(BatDJC400x800);%axis([0 800 0 400 -60 -10]);
    az= -37.5; el = 30;
    az= -38; el = 66;
    view(az,el);
    colormap copper;
    shading interp
end

adaptnoise = 0;
adaptssize = 0;
sonarconfig = 5;


%Global Variables
global MAP_RESOLUTION;
global invalid_depth;
global Toler_grad;
global BEACON_POS;
% Inputs
vehidepth  = 0;
%Initial Conditions
blacki.Xp  = [blacki.Xp(1,:)-refX; blacki.Xp(2,:)-refY];
indx1=find(blacki.beacon_pos(1,:)>-1);
blacki.beacon_pos(:,indx1)  = [blacki.beacon_pos(1,indx1)-refX; blacki.beacon_pos(2,indx1)-refY];

indx2=find(blacki.beacon_alt_pos(1,:)>-1);
blacki.beacon_alt_pos(:,indx2)  = [blacki.beacon_alt_pos(1,indx2)-refX; blacki.beacon_alt_pos(2,indx2)-refY];



%  Xt0 = [250; 150];
Xt0(1,1) = blacki.Xp(2,1);%[230; 265];
Xt0(2,1) = blacki.Xp(1,1);%[230; 265];
%Psi0 = 270*pi/180;

vehidepth2  = 0;
BEACON_POS  = 1;%[];


%Psi0 = atan(2);
% Paramaters
MAP_RESOLUTION = 1;
invalid_depth  = -99999;
Toler_grad     = 1e-6; % smallest gradient considered different from zero (used in gradient transformation by Rotation matrix)

M    = 1;
Ns(1)   = 400;  % Particles for vehicle position estimation
Nextra=100;    % Num of extra particles unif.distrib. around estimated position of vehicle (used in MC3_TAN_PF_SISR9_adapt_unifp_reinit)

Ns(2)   = 200; % Particle for beacon estimation
Nextra(2) = 300;

plotdeadreck =0;

if M<2
    plotsimmaps =10;
    plotdeadreck = 0;
else
     plotsimmaps =0;
end

T = 0.2;
pf_ver= 1;


t = 0:T:95;
blacki.ntt;
N = length(blacki.ntt);



%[Yp,Yt,Up,Xt,Xp,dhT_dX,Std_merror] = Generate_data_TANSBN(BatDJC400x800,dMap_dx,dMap_dy,theta, Vel,yawrt, T, Psi0,Xt0,vehidepth,N);

%[Yp,Yt,Up, Xp,Xt2] 
%[Y,Yt,U,Xt,Xt2,Xd,dhT_dX,Std_merror]    = Generate_data_cooperative_TAN_expo(Map,dMap_dx,dMap_dy,          theta,T,Xt0,z,z2, N)
[Yp,Yt,Up, Xt,Xt2,Xp,dhT_dX,Std_merror] = Generate_data_cooperative_TAN_expo(blacki,BatDJC400x800,dMap_dx,dMap_dy,theta_beam, T,Xt0,vehidepth,vehidepth2, N); % 1.2 for surfer

% 
% 
% figure; contour(BatDJC400x800,20); grid on; colorbar;
% title('True Trajectory'), xlabel('Y=Easting (meters)'), ylabel('X=Northing (meters)')
% %open('djcastroctr2.fig'); title('Trajectories used in the simulations')
% hold on
% plot(Xt(2,1),Xt(1,1),'o', 'MarkerEdgeColor','k',...
%     'MarkerFaceColor','r',...
%     'MarkerSize',8); % Becon position of the vehicle
% plot(Xt2(2,indx1(1)),Xt2(1,indx1(1)),'o', 'MarkerEdgeColor','k',...
%     'MarkerFaceColor','b',...
%     'MarkerSize',8); % Becon position of the vehicle
% 
% plot(Xt(2,:),Xt(1,:),'.-r')
% plot(Xt2(2,indx1),Xt2(1,indx1),'-.b')
% 
% plot(Xp(2,:),Xp(1,:),'--k')
% 
% %plot( Xhat(:,2), Xhat(:,1),'.-b')
% 
figure,
subplot(3,1,1), plot(Yp(1,:),'.r'), grid on, hold on, plot(Yt(1,:),'.b'),title('veh1'),
subplot(3,1,2), plot(Yp(2,:),'.r'), grid on, hold on, plot(Yt(2,:),'.b'), title('Interrange')
subplot(3,1,3), plot(Yp(3,:),'.r'), grid on, hold on, plot(Yt(3,:),'.b'), title('Veh2')
hold off;

%%
% ss = 100;%[Yp,Yt,Up,Xt,Xp,~]
% ee = length(Xp)-10;
% Xp = Xp(:,ss:ee);
% Up = Up(:,ss:ee);
% Yp = Yp(:,ss:ee);
% Xt = Xt(:,ss:ee);
% Yt = Yt(:,ss:ee);
% 
% N = length(Yt);

CRLBs = Compute_CRLB(dhT_dX,Std_merror,T);
% figure, 
% stairs(0:T:(N-1)*T,CRLBs(1,:),'--k','LineWidth',2), grid on

%BEACON_POS =  [];

%%
sumsquareEx_pos=zeros(1,N);
%sumsquareEx_bec=zeros(1,N);
P_hatb_store = 0;
if(~isempty(BEACON_POS))
    Ex(:,:,:) = zeros(2,N,M);
    Av_X_hat1 = zeros(2,N);
    X_hat_store = zeros(2,N,M);
    P_hat_store  = zeros(2,2,N,M);
    P_hatb_store = zeros(2,2,N,M);
else
     Ex(:,:,:) = zeros(2,N,M);
     Av_X_hat1 = zeros(2,N);
     X_hat_store = zeros(2,N,M);
     P_hat_store  = zeros(2,2,N,M);
end
%%
pause(1)
close all;
%matlabpool open;
for m=1:M

%     [Yp,Yt,Up,Xt,Xp] = Generate_data_TANSBN(BatDJC400x800,dMap_dx,dMap_dy,theta, Vel,yawrt, T, Psi0,Xt0,vehidepth,N);
%     ss = 50;
%     ee = length(Xp)-10;
%     Xp = Xp(:,ss:ee);
%     Up = Up(:,ss:ee);
%     Yp = Yp(:,ss:ee);
%     Xt = Xt(:,ss:ee);
%     Yt = Yt(:,ss:ee);
%     plotdeadreck =1;
% %[Xd] = Generate_data_TANSBN_dead(Vel,yawrt, T, Psi0,Xt0,N)
% if plotdeadreck
%     figure; contour(BatDJC400x800,20);%axis equal;
%     grid on; title('Trajectory of the Vehicle');
%     xlabel('Easting (meters)')
%     ylabel('Northing (meters)')
%     hold on
%     plot(Xt(2,:),Xt(1,:))
%     plot(Xp(2,:),Xp(1,:),'.k')
%     if(~isempty(BEACON_POS))
%         plot(BEACON_POS(2),BEACON_POS(1),'vb', 'MarkerEdgeColor','k',...
%             'MarkerFaceColor','b',...
%             'MarkerSize',8); % Becon position of the vehicle
%         
%     end
% end
X0hat =   Xp(:,1);% [212.8950 ; 175.7726];%Xp(:,1);% [  253.7870;  128.1541];%Xp(:,1);%[ 247.0744; 146.5852];%
fprintf('Run no... %1.0f\n',m);
%%
[X_hat,P_hat,P_hatb, F] = Run_Filter_pf_gps3(BatDJC400x800,dMap_dx,dMap_dy,Ns,Nextra,adaptssize,adaptnoise, sonarconfig, theta,Xt2,Xt,X0hat,Yt,Up,N,T,plotsimmaps,m);
X_hat_store(:,:,m) = X_hat;

 % estimation error at run k
 % Av_X_hat1 = Av_X_hat1 + X_hat;

 if(~isempty(BEACON_POS))
   %  Ex(:,:,m) = [Xt(:,1:N);BEACON_POS(1:2)*ones(1,N)] -  X_hat;
     P_hat_store(:,:,:,m)  = P_hat;
    % P_hatb_store(:,:,:,m) = P_hatb;
 else
    % Ex(:,:,m) = Xt(:,1:N) -  X_hat;
     P_hat_store(:,:,:,m) = P_hat;
 end
 Map = BatDJC400x800;
save('lastdata.mat', 'Map', 'BEACON_POS','CRLBs','F','Xt2', 'Xt', 'X_hat_store','P_hat_store','P_hatb_store','N','m', 'T'); 
end
%%
if(length(F)>1)
    %makemovie(F,'TANSBNRealData_new.avi',0);
end

Map = BatDJC400x800;
save('lastdata.mat', 'Map', 'BEACON_POS','CRLBs','F','Xt2', 'Xt', 'X_hat_store','P_hat_store','P_hatb_store','N','M', 'T');
  
%%
load lastdata;
plotandsave;