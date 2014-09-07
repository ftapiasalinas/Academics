function [Y,Yt,U,Xt,Xt2,Xd,dhT_dX,Std_merror] = Generate_data_cooperative_TAN_expo(blacki,Map,dMap_dx,dMap_dy,theta,T,Xt0,z,z2, N)
global MAP_RESOLUTION;
%global BEACON_POS;

simrange =1;

[L C] = size(Map);
L=L*MAP_RESOLUTION;
C=C*MAP_RESOLUTION;
U        = blacki.Up;
U(1,:)   = blacki.Up(2,:);
U(2,:)   = blacki.Up(1,:);
Xt(1,:)  = blacki.Xp(2,:);
Xt(2,:)  = blacki.Xp(1,:);
Xd  = zeros(2,N);
Xt2(1,:)  = blacki.beacon_pos(2,:); % Position of Beacon,  when range measurement is avaialble
Xt2(2,:)  = blacki.beacon_pos(1,:);
Xt_alt2(1,:)  = blacki.beacon_alt_pos(2,:);% Position of Beacon,  when altimeter data on becaon is available 
Xt_alt2(2,:)  = blacki.beacon_alt_pos(1,:);

Yt            =   blacki.Yp;%(1,:);
%Yt(1,:)       =  -blacki.Yp(1,:);
%indx1         =   find(blacki.Yp(3,:)>0)
%Yt(3,indx1)   =  -blacki.Yp(3,indx1);
Y  = Yt;

Std_merror = zeros(3,N);
dhT_dX = zeros(2,3,N);
Psi = blacki.imupsi;

LoadFilterNoises;
Xd(:,1) = [ 305.7218; 72.3283];%Xt0 + 0.5*Sd0(1,1).*randn(2,1).*sqrt(T); % [249.77;187.88]; bad initial condition
sd_process = [std_pnx;std_pny].*sqrt(T); %process noise std dev. in discrete time
process_noise = sd_process*ones(1,N).*randn(2,N);


for t=1:N
    
    % Kinematics veh2
    Vx = U(1,t);
    Vy = U(2,t);
    Xd(:,t+1) = Xd(:,t) + [Vx;Vy].*T ;%+ process_noise(:,t);  % dead reckoning
    
    
    %+++++++Generate measurement+++++++++++++++++++++
    %++++++++++++++++++++++++++++++++++++++++++++++++
    x = Xt(1,t);y = Xt(2,t);
    x2 = Xt2(1,t);y2 = Xt2(2,t);
    % measurement vehicle 1
    if fix(x+1)+1 > L | fix(y+1)+1 > C | x < 0 | y <0 % validate coordinates (see script Map_valid)
        error('WARNING: invalid coordinates specified in sim_nav_3beam6MC.m: %5.1f %5.1f', x, y);
    end
    
    dh1_dX = [Map_valid(dMap_dx,x,y);  Map_valid(dMap_dy,x,y)];
    
    depth1=Map_valid2(Map,x,y); % true depth (at the vertical of the 1st sensor)
    true_vert_range=(depth1-z); % subtract vehicle depth to obtain true sonar range
    [range1,~, ~, sd_t]=calc_mdepths3(Map,dMap_dx, dMap_dy, [x;y], z,0,0,Psi(t), pi/2, 0,theta); % Sonar model gives ranges with noise
    
    
    if(Yt(2,t)>0)
        %   [rangeSB, ~, ~, ~, ~] = calc_beaconRange([x;y;z],sd_range,eta_range,1,BEACON_POS); % true range (from Beacon)
        %[rangeSB, ~, ~, sd_r,Dr_dx,Dr_dy] = calc_vehRange([x;y;z],[x2;y2;z2],1); % true range (from Beacon)
        [rangeSB, ~, ~, sd_r,Dr_dx,Dr_dy] = calc_vehRange([x;y;z],[x2;y2;z2],1); % true range (from Beacon)
       % rangeSB = Yt(2,t);
        % measurement vehicle 2
        if fix(x2+1)+1 > L | fix(y2+1)+1 > C | x2 < 0 | y2 <0 % validate coordinates (see script Map_valid)
            error('WARNING: invalid coordinates specified in sim_nav_3beam6MC.m: %5.1f %5.1f', x2, y2);
        end
    else
        rangeSB = -1;
        Dr_dx = 0;
        Dr_dy = 0;
        sd_r = 999999;
    end
    
    if(Yt(3,t)>0)
        x2a = Xt_alt2(1,t);y2a = Xt_alt2(2,t);
           % measurement vehicle 2
        if fix(x2a+1)+1 > L | fix(y2a+1)+1 > C | x2a < 0 | y2a <0 % validate coordinates (see script Map_valid)
            error('WARNING: invalid coordinates specified in sim_nav_3beam6MC.m: %5.1f %5.1f', x2a, y2a);
        end
        depth2=Map_valid2(Map,x2a,y2a); % true depth (at the vertical of the 1st sensor)
        true_vert_range2=(depth2-z2); % subtract vehicle depth to obtain true sonar range
        
        if simrange && Yt(2,t)<0
            [rangeSB, ~, ~, sd_r,Dr_dx,Dr_dy] = calc_vehRange([x2a;y2a;z2],[x;y;z2],1); % true range (from Beacon)
            Yt(2,t) = rangeSB;
            Xt2(1,t) = x2a;
            Xt2(2,t) = y2a;
        end
    else
        sd_t2= 999999;
        true_vert_range2=-1;
    end
    dh4_dX = [Dr_dx; Dr_dy];
    dh2_dX = [0; 0];
    dhT_dX(:,:,t)=[dh1_dX , dh4_dX, dh2_dX];
    Std_merror(:,t) = [sd_t;sd_r; sd_t2];
    Y(:,t) = [true_vert_range; rangeSB; true_vert_range2];
end
dhT_dX(:,:,1) = dhT_dX(:,:,2);
Std_merror(:,1) = Std_merror(:,2);