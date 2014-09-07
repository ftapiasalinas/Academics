function [X_hat,P_hat,P_hatb,F] = Run_Filter_pf_gps3(Map,dMap_dx,dMap_dy,Ns,Nextra,adaptssize,adaptnoise, sonarconfig, theta,Xt2,Xp,X0hat,Yp,Up,N,T,plotsimmaps,RunNo)

%global T % time interval between iterations (sec)
global Toler_grad
global InfoMatrix_Tol % used in calc_filter_information_matrix4
global addnoise_pf   % added process noise to spread the particles more (defined in SIS ou SIR PF)
global MAP_RESOLUTION % Altera��o introduzida (FEV/2008) p/ permitir utiliza��o de mapas c/ resolu��es diferentes de 1m (ver Notas G)
global BEACON_POS;


%% Intialize outputs PKM

%BEACON_POS = BeaconPos;
MAP_RESOLUTION=1;

o=1; % first Matlab index value
InfoTol=1E-9;
InfoMatrix_Tol=eye(4)*InfoTol;

Inicio=clock; % tempo inicial
Toler_grad=1e-6; % smallest gradient considered different from zero (used in gradient transformation by Rotation matrix)

Nmin=100; % Minimum number of particles used by the filter
Nmax=3000; % Nmax=1000; % Maximum number of particles used by the filter

Max_pos_error=5000; % if position error > Max_pos_error during more than Max_time_error (seconds),
% then filter is considered to diverge
Max_time_error=3000; % time in seconds used to determine filter divergence
Aextra = [15 0; 0 15]; % matrix to establish the area (15m x 15m) for uniform distribution of extra particles
%plotsimmaps=0;    % plot maps during real-time simulation of vehicle navigation
Xt=Xp(:,1:N);

% % Apply TAN_Particle_Filter to obtain estimates and covariances
% LoadFilterNoises
% %X0hat= Xp(:,1) + Sd0(1,1)*randn(2,1).*sqrt(T);%(Sd0-diag([25 25]))
% %X0hat(1:2) = [271.8789 ;127.6669];
% % thtmp= 2*pi*rand;
% % sigIni = Sd0(3,3);
% if 0
%     while 1
%         ss = (diag([Sd0(3,3) Sd0(4,4)])*randn(2,100));
%         Indx = find(ss(1,:)<68*Sd0(3,3)/100);
%         Indy = find(ss(1,:)<68*Sd0(4,4)/100);
%         if ~isempty(Indx) && ~isempty(Indy)
%             X0hat(3:4) = BEACON_POS(1:2) + [ss(1,Indx(1));ss(2,Indx(1))];
%             break;
%         end
%     end
%            
%     
% %     BTemp = BEACON_POS(1:2) + [2*sigIni*cos(thtmp);2*sigIni*sin(thtmp)];
% %     if(~isempty(BEACON_POS))
% %         X0hat(3:4) = BTemp + sigIni*0.05*randn(2,1).*sqrt(T);%[  338.5542;  238.9791];
% %     end
% else
%     if(~isempty(BEACON_POS))
%         X0hat(3) = BEACON_POS(1)  + Sd0(3,3).*rand(1,1);%[Sd0(3,3);Sd0(4,4)]*randn(2,1).*sqrt(T);%[  338.5542;  238.9791];
%         X0hat(4) = BEACON_POS(2)  + Sd0(4,4).*rand(1,1);
%         % [310.46;260.21] bad intial
%     end
% end
[X_hat,P_hat,P_hatb,F,Npart,Qk,fdiverges,simtime,Nreinit] = ...
    MC3_TANSBN_Filter_new_gps_den_Brownian3(Nmin,Nmax,Nextra,Aextra,Max_pos_error,Max_time_error,X0hat,Xt2,Xt,Up,Yp,Ns,N,Map,dMap_dx,dMap_dy,adaptssize,adaptnoise,plotsimmaps,sonarconfig,theta,T,RunNo);
%  MC3_TANSBN_Filter_new_gps_den_n
%+++++++++++++++++++++++++++++++++++++++
Total_time=etime(clock,Inicio)
%% ############################################################################################################
% save('lastdata.mat', 'Map', 'BEACON_POS', 'Xt', 'X_hat','P_hat','N', 'T');
% clear all;
% %%
% for s1=1:length(P_hat)
%     Stdx(:,s1)=sqrt(diag(P_hat(1,1,s1))); % estimated (pseudo) standard devs at run k
%     Stdy(:,s1)=sqrt(diag(P_hat(2,2,s1))); % estimated (pseudo) standard devs at run k
%     
%     Stdbx(:,s1)=sqrt(diag(P_hat(3,3,s1))); % estimated (pseudo) standard devs at run k
%     Stdby(:,s1)=sqrt(diag(P_hat(4,4,s1))); % estimated (pseudo) standard devs at run k
% end
% ttl = 'Trajectories used in the simulations - (depth contour in meters)';
% ttl1 = 'RMS Error';
% if(isempty(BEACON_POS))
%     ttl  = strcat(ttl,' TAN Only');
%     ttl1 = strcat(ttl1,' TAN Only');
%     save('TANOnly1.mat', 'Map', 'BEACON_POS', 'Xt', 'X_hat','P_hat','Ex','N', 'T');
% end 
% if(~isempty(BEACON_POS))
%   save('TANSBN1.mat', 'Map', 'BEACON_POS', 'Xt', 'X_hat','P_hat','Ex','N', 'T');
% end
% %%
% figure; contour(Map,20); grid on; colorbar;
% title(ttl), xlabel('Y=Easting (meters)'), ylabel('X=Northing (meters)')
% %open('djcastroctr2.fig'); title('Trajectories used in the simulations')
% hold on
% if(~isempty(BEACON_POS))
%     plot(BEACON_POS(2),BEACON_POS(1),'vb', 'MarkerEdgeColor','k',...
%         'MarkerFaceColor','b',...
%         'MarkerSize',8); % Becon position of the vehicle
%     plot(X_hat(4,:),X_hat(3,:),'.-r','LineWidth',2)
%     plot(X_hat(4,end),X_hat(3,end),'or', 'MarkerEdgeColor','k',...
%         'MarkerFaceColor','r',...
%         'MarkerSize',8); % Becon position of the vehicle
%    
% end
% plot(Xt(2,:),Xt(1,:),'-k','LineWidth',2)
% plot(X_hat(2,:),X_hat(1,:),'r','LineWidth',2)
% %%
% for t=1:N
%     sumsquareEx_pos(t)=Ex(1:2,t)'*Ex(1:2,t);
%     sumsquareEx_bec(t)=Ex(3:4,t)'*Ex(3:4,t);
% end
% hold off;
% figure; % Position error
% ylabel('position error (m)'), xlabel('t (s)')
% stairs(0:T:(N-1)*T,sqrt(sumsquareEx_pos(1:N)),'-k','LineWidth',2), hold on
% stairs(0:T:(N-1)*T,sqrt(sumsquareEx_bec(1:N)),'-b','LineWidth',2)
% title(ttl1), grid on
% legend('err veh pos','err beacon pos')
