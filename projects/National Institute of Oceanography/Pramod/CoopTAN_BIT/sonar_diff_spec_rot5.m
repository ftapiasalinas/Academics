function [x1, y1, z1, r1, xt, yt, zt, rtrue, missed_return] = sonar_diff_spec_rot4(ping,Map,dMap_dx,dMap_dy,rmin,rmax,phi_s,x0,y0,z0,sigma_alpha,rho,psi,plot_components)
% Version 5 (based on version 4)
% Diferença da vers. 4: corrige o problema no cálculo dos limites do ciclo gerado pela
%  instrução:         for rho_i=(rho - asin(sqrt(sin(phi_s/2)^2-sin(psi_i)^2))):dBetai:(rho + asin(sqrt(sin(phi_s/2)^2-sin(psi_i)^2)));
%  em que eram gerados valores negativos para o argumento de sqrt() =>
%
% Simulates a sonar return from a diffuse reflector: instead of the depth measured in the vertical of the sonar, the range measured 
% by the sonar sensor is calculated based on the intensity of the incident beam and the angle of incidence on
% the surface at each point inside the cone defined by the sonar aperture, using a treshold for return detection based on
% the intensity of the return calculated applying Lambert's law.
% Note: in this version when missing a return from the sonar ping, the flag missed_return=1 is initialised but
%   the largest range measured inside the insonified area is returned anyway

% Francisco Curado Teixeira
% 19/Nov/2004. Revised 17/06/2005 (vers.4)
% Sonar return is detected when the amplitude is above a certain threshold.
% Ver notas em : "AUV-TAN", Notas-F ("Simulaçao de Retorno Sonar")
% Bibliog.Refs: 
% 1. Urick, 1983. Principles of underwater sound (3rd Ed.). (Peninsula Publishing)
% 2. Adams, 1999. Sensor Modelling, Design and Data Processing for Autonomous Navigation. (World Scientific)
% 3. FC-343; 
% 4. FC-324;
% 5. FC-372
% 6. NT-11
% 7. NT-12

% INPUT:
%   ping = ping number
%   Map = bathymetric matrix: X=North direction; Y=East direction (column=const YY; line=const XX)
%   dMap_dx, dMap_dy = partial gradients of the bathymetric map reprsented in matrix Map
%   rmin =  minimum range to start searching for reflector
%   rmax =  maximum range to end searching for reflector
%   phi_s = effective sonar aperture (degrees)
%   x0, y0, z0 = 3D coordinates of the sensor (sonar) location 
%   sigma_alpha = std.dev.of the slope of the micro-facet (rad): parameter of surface roughness (see FC-324, FC-343, FC-372)
%   rho = inclination: angle of sonar beam relative to horizontal (rad) (rho2 is positive, since depth is assumed positive)
%   psi = azimuth: angle of sonar beam relative to North (rad) (clockwise = positive)
%   plot_components = boolean: calculate and plot reflection components (only for analysis tests)

% OUTPUT:
%   x1, y1, z1 = 3D coordinates of the point corresponding to the range measured by the sonar 
%   z1 = true depth of the point with smallest range
%   r1 = range, is a positive value that corresponds to the distance measured by the sonar
%   xt, yt, zt = true 3D coordinates of the point corresponding to the true range
%   rtrue = true range (without any error)
%   missed_return = (1/0) the sonar return does not attain the Detection Threshold (DT)

% Other variables:
%   areasr = array [x, y, h, R_k, I_back, thetai_k] of set of attributes of elementary areas of reflection for each sub-beam
%       (x,y=2D coord; h=altitude; R_k=range; I_back= intensity of backscattered signal; thetai_k=angle of incidence at bottom surface)
%   rcompon = array [psi_i, rho_i, Pr_dc, Pr_sc] of reflection fractional parts of
%       of diffuse and specular components for each sub-beam characterized by (psi_i, rho_i)

global sigma

global MAP_RESOLUTION % Alteração introduzida (FEV/2008) p/ permitir utilização de mapas c/ resoluções diferentes de 1m (ver Notas G)

warning off % Suprimiu-se temporariamente os Warnings gerados pelo Matlab devido ao problema acima referido

% Constantes: COMMENT if these are declared global and initialized in external function
sigma = sigma_alpha; % ATENÇAO: 'global sigma' indispensavel p/ calculo do integral quad(@exp_normal,0,pi/2)

if plot_components
   rcompon = []; 
end

missed_return=0;

[dummy1, stdm, kstdm, dummy2, dummy3, dummy4] = sonar_physic_consts(phi_s);
phi_s=deg2rad(phi_s);
A1 = phi_s; % Area (m^2) of spherical wave-front at 1 meter for a sonar beam-width = phi_s
dAi = 25*pi*1e-4; % surface area of sensor (m^2): sensor with 10 cm diameter

if phi_s <= deg2rad(5)
    dsolid_angle=0.25; % elementary solid angle of incidence (deg) ; 
else   
    dsolid_angle=1; % elementary solid angle of incidence (deg) ; (testado com dsolid_angle = 0.25, 1 : resultados mediçoes iguais)
end

dBetai = deg2rad(dsolid_angle);  % elementary solid angle of incidence (rad) 
cnorm = 1/quad(@exp_normal,0,pi/2); % normalization const of the pdf of angles of facets (see FC-343; pg.619)

speedsw = 1500; % speed of sound in sea water (m/s)

P0=1000; % Power applied by acoustic source (W)
I0 = P0/A1; % Intensity of the acoustic wave at 1 meter 

DTfactor=1;  % fraction of true DT used to facilitate the detection
% Toler_grad=1e-12;

di=16 ; % detection index
W=500; % signal badwidth (Hz)
t=0.01; % signal duration (sec)
SNR2=di/(W*t); % Signal/Noise Ratio squared
DT=5*log10((di*W/t))*DTfactor; % Detection Treshold for a well matched signal (with di=16, W=500, t=0.01 => DT=29.5)
NW=10;%1000; % Noise power in bandwidth W (in watts) (probably is much lower than 1000 W)

Ksl = 0.3; Kdl = 0.7; % reflectance parameters depending on surface type (here arbitrary)
alpha_abs=1.3e-4; % @ 10KHz; logarithmic absorption coefficient as a function of range(dB/m) for a given frequency
%alpha_abs=5.8e-3; % @ 100KHz; logarithmic absorption coefficient as a function of range(dB/m) for a given frequency

tant2=tan(phi_s/2);

%[L C] = size(Map)*MAP_RESOLUTION;
[L C] = size(Map); L=L*MAP_RESOLUTION; C=C*MAP_RESOLUTION;

x1=x0; y1=y0; 

areasr=[]; % Array (Nx5) of reflection point attributes 
t_areasr=0; % ? total number of elementary areas of reflection

if fix(x0+1)+1 > L | fix(y0+1)+1 > C | x0 < 0 | y0 <0 % validate coordinates (see script Map_valid)
    disp(['WARNING (sonar_diff_spec_rot): invalid coordinates specified : ' num2str(x0) ',' num2str(y0)])
    disp('Possible cause: trajectory approaches map boundaries')
    z1=z0; r1=0; rtrue=0; xt=0; yt=0; zt=0;% values not valid    
else
    % Calculate true range and depth of the point of incidence of the ray defined by p0, psi, rho :
    p0=[x0;y0;z0]; % coordinates of sensor
    [rtrue,calcdepth,z1,x,y,z]=calc_depth3(Map, p0, rmin, rmax, psi, rho, 1, 0); 
%   [range,calcdepth,depth,x,y,z]=calc_depth3(Map, p0, rmin, rmax, psi, rho, deterministic,errorlevel)
    xt=x; yt=y; zt=z1;
    r1=rtrue;
    for psi_j= - phi_s/2:dBetai:phi_s/2
        psi_i= psi + psi_j;
%   for psi_i = (psi - phi_s/2):dBetai:(psi + phi_s/2)
%         for rho_i=(rho - asin(sqrt(sin(phi_s/2)^2-sin(psi_i)^2))):dBetai:(rho + asin(sqrt(sin(phi_s/2)^2-sin(psi_i)^2)));
            for rho_i=(rho - asin(sqrt(sin(phi_s/2)^2-sin(psi_j)^2))):dBetai:(rho + asin(sqrt(sin(phi_s/2)^2-sin(psi_j)^2)));

                [R_k,calcdepth,z1,x,y,z]=calc_depth3(Map, p0, rmin, rmax, psi_i, rho_i, 1,0);

                if x > L
                    disp(['WARNING (sonar_diff_spec_rot): invalid coordinates x = ' num2str(x)])
                    break
                else
                    if x<0  % because we can have  x0 < p0
                        disp(['WARNING (sonar_diff_spec_rot): invalid coordinates x = ' num2str(x) 'converted to 1'] )
                        x=1;
                    end
                end
                if y > C
                    disp(['WARNING (sonar_diff_spec_rot): invalid coordinates y = ' num2str(y)])
                    break
                else
                    if y<0
                        disp(['WARNING (sonar_diff_spec_rot): invalid coordinates y = ' num2str(y) 'converted to 1'] )
                        y=1;
                    end
                end
                depth=-Map_valid(Map,x,y);  h=depth-z0; %depth=depth; h=altitude
                %               R_k = current range (of point (x,y,z)
                %               Evaluate angle of incidence on the surface at that point:
                kx=-Map_valid(dMap_dx,x,y); % partial gradients at point of incidence (with
                ky=-Map_valid(dMap_dy,x,y); % signal reversed because z axis points downwards in our frame)
                %             gradx=[1; 0; kx];  grady=[0; 1; ky]; % vectors that span the gradient
                xi=x-x0; yi=y-y0; zi=h; % coordinates relative to sensor
                % Calculate thetai_k , the angle between the sub-beam and the normal to the elementary surface at point of incidence:
                thetai_k= acos((-kx*xi -ky*yi + zi)/sqrt((kx^2 + ky^2 +1)*(xi^2 + yi^2 + zi^2)));
                if R_k ~= 0
                    Loss=exp(-R_k*alpha_abs)/R_k^2; % Evaluate Absorption and Spreading-Loss attenuation factor: Loss
                else
                    Loss=1;
                end
                nu_alpha=0; % mean slope of micro-facets relative to the elementary surface
                p_thetai_k=... % probability of facets with slope equal to the angle of incidence thetai_k
                    cnorm*exp_norm_scalar(thetai_k,nu_alpha,sigma_alpha) ; % is normally distributted N(0,sigma_alpha^2)
                G_thetai_k=min([1, 2*cos(thetai_k)^2]); % Geometric attenuation factor
                if R_k ~= 0
                    dBetar_k = dAi/R_k^2; % elementary angle of reflection from the subsurface to the receiver
                else
                    dBetar_k = pi;
                    disp('Warning (sonar_diff_spec_rot4): range from source to reflector is zero ')
                end
                % Power of backscattered signal including specular and diffuse components: Pr_k
                if cos(thetai_k) ~= 0
                    % calculate sub-beam power reflected (specular + diffuse components) back to the source
                    Pr_dc = abs(Kdl*cos(thetai_k)); % diffuse component
                    Pr_sc = abs(Ksl*p_thetai_k*G_thetai_k*dBetar_k)/(2*pi*cos(thetai_k)); % specular component
                    %                 Pr_k = I0*dBetai*Loss^2*(abs(Kdl*cos(thetai_k)) + abs(Ksl*p_thetai_k*G_thetai_k*dBetar_k)/(2*pi*cos(thetai_k)));
                else
                    Pr_dc = 0; Pr_sc = 0;
                    % Pr_k = 0;
                end
                Pr_k = I0*dBetai*Loss^2*(Pr_dc + Pr_sc); % Apply factor Loss^2 to account for TWT loss in the reception
                if plot_components
                    if (Pr_dc + Pr_sc) ~=0
                        rcompon = [rcompon; psi_i, rho_i, I0*dBetai*Loss^2*Pr_dc, I0*dBetai*Loss^2*Pr_sc];
                    else
                        rcompon = [rcompon; psi_i, rho_i, 0, 0];
                    end
                end
                areasr=[areasr; [x, y, h, R_k, Pr_k, rad2deg(thetai_k)]];
                t_areasr=t_areasr+1;
                % %             end
%             end
        end
    end
   
    areasr=sortrows(areasr,[4]);  % sort  array of reflection areasr by range
    j=0; Pr_sum=0; Pr_level=-Inf;
    if t_areasr > 0
        ri=areasr(1,4);
        R_k=ri;
    end
    while j< t_areasr & Pr_level < DT
        j=j+1;
        rj=areasr(j,4); % diff in range between first and current reflection R_k=rj;                 
        Pr_sum=Pr_sum+areasr(j,5); % add back-reflected power of each elementary area
        if R_k ~= 0
            Pr_sum = Pr_sum / (exp(-R_k*alpha_abs)/R_k^2)^2; % Absorption & Spread Loss compensation for TWT
        end
        if Pr_sum==0
            Pr_level=0; % Level of backscattered signal
        else
            Pr_level=10*log10(Pr_sum/NW); % Level of backscattered signal        
        end
        if Pr_level < DT
            dt=2*(rj - ri)/speedsw; % additional signal lenght introduced by multiple reflections
            DT=5*log10((W^2*t/(t+dt))*SNR2)*DTfactor; % Recalculate Detection Treshold (decrease as a function of range)
        end
    end
    if Pr_level < DT
        missed_return=1;
        disp(['WARNING (sonar_diff_spec_rot): no return from sonar ping#' num2str(ping) ' at: ' num2str(x0) ',' num2str(y0)])
        disp('Possible cause: Detection Threshold too high  or point beyhond map boundaries')
    end   
    x1=areasr(j,1); y1=areasr(j,2); z1=areasr(j,3); r1=areasr(j,4); 
    if plot_components
        % plot reflection components (only for analysis tests)
        figure
        subplot(2,1,1)
        plot(1:length(rcompon),rcompon(:,1),'k-',1:length(rcompon),rcompon(:,2),'k--')
        ylabel('incidence angles (rad)')
        legend('psi','rho')
        title(['Angles of incidence of sub-beams and Reflection components ; facet slope StdDev = ' num2str(rad2deg(sigma_alpha)) 'deg'])
        subplot(2,1,2)
        plot(1:length(rcompon),rcompon(:,3),'k-',1:length(rcompon),rcompon(:,4),'k--')
        ylabel('reflection power (W)')
        legend('diff','spec')
        xlabel('sub-beam number')
    end
end


