function [r, err, ud, sd] = predict_beaconRange(p0,z,pb,zb, deterministic)
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

eta = 0;%0.0001;
Noofpoints = length(p0(1,:));
sd  = 2.*ones(1,Noofpoints);
ud  = 0.*ones(1,Noofpoints);
r = zeros(1,Noofpoints);
err = zeros(1,Noofpoints);

pos1 = [p0; z.*ones(1,Noofpoints)];
pos2 = [pb; zb.*ones(1,Noofpoints)];

poserr = pos1-pos2;
r = sqrt(sum(poserr.^2,1));

if ~deterministic        
    err = ud + (1+eta.*r).*randn(1,Noofpoints).*sd;
    r = r + err; % add gaussian noise if simulation is stochastic (Noise varies with distance)    
end
% range=r;
% err = err';
% ud = ud';
% sd= sd';