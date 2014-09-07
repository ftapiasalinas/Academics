function [range, err, ud, sd,Dr_dx,Dr_dy] = calc_beaconRange(p0, deterministic)
% Calculate depth and range of the point corresponding to the intersection of
% the beam-vector defined by the azimuth (psi) and elevation (rho) angles with the
% sea-bottom represented in Matrix Map.
% It is assumed that the beam is a ray and reflection is diffuse (i.e. independent of the angle of the surface).
% Vers. 3
% Difference from vers.2: also output the 3D coordinates of the reflection point (besides true depth and calculated depth)
%
% INPUTS:
%   p0 = 3D coordinates [x;y;z] of vector starting point (coordinates of the sensor)
%   deterministic = 1/0 : indicates if noise is added or not

% OUTPUTS:
%   range = distance from sonar sensor to the reflector (with noise if simulation is stochastic)

global BEACON_POS% Alteração introduzida (FEV/2008) p/ permitir utilização de mapas c/ resoluções diferentes de 1m (ver Notas G)

eta = 0;%0.0001;
sd  = 0.5;
ud  = 0;

rt = norm(p0 - BEACON_POS);
err = 0;
r =rt;
if ~deterministic        
    err = ud + (1+eta*r)*randn*sd;
    r = rt + err; % add gaussian noise if simulation is stochastic (Noise varies with distance)    
end
Dr_dx = (p0(1)-BEACON_POS(1))/rt;
Dr_dy = (p0(2)-BEACON_POS(2))/rt;
range=r;
sd = (1+eta*rt)*sd;