function [Xpfr,depths,ud,sd]=calc_mdepths3(Map,dMap_dx, dMap_dy, Xpfp0, z0, rmin, rmax, psi, rho, deterministic,theta)
% Compute ranges and depths for a set of points (possible vehicle
% positions) simultaneously using arrays, assuming a oblique sonar beam (with diffuse reflection), calculating the intersection point
% of the beam with the bottom surface using binary search. Compute also the statistical parameters of the measurement error at each point as 
% a function of range, local gradient and sonar configuration.
%
% Vers. calc_mdepths3 (based on calc_mdepths2) : use statistical approximation to physical model to determine the
% parameters of the error distribution (see Tech. Report)

% INPUTS:
%   Map = bathymetric map
%   dMap_dx, dMap_dy = gradients of Map relative to x and y
%   Xpfp0 =(2xN) array of (x,y) coordinates of start-point of vectors used to search bottom-reflectors (x,y in meters)
%   z0 = (positive value in meters) depth of the particles (since depth is a measurement, it is the same for all particles) 
%   rmin = minimum magnitude of the vectors (since the minimum depth is known from the map)
%   rmax = maximum magnitude of the vectors (since the maximum depth is known from the map)
%   psi = azimuth (rad)
%   rho = elevation (rad) (note: rho is a positive angle measured from the horizontal, since depth is assumed positive)
%   deterministic = 1/0 : indicates if noise is added or not to the true ranges obtained from the map
%   theta = sonar beam width (degrees) 

% OUTPUTS:
%   Xpfr= (1xN) array of true ranges to the bottom-reflection points (1 for each particle) obtained from the map
%   depths = (1xN) array of true total depths (at the vertical of each reflection point)
%   ud, sd = (1xN) arrays of measur. error parameters (mean and std.dev of error as function of range, gradient, and sonar aperture)

% AUX. VARIABLES:
%   Xpfrmax = (1xN) array of maximum length of vector r 
%   Xpfrmin = (1xN) array of minimum length of vector r (1 for each particle)
%   Xpfp    = current 3D coordinates of vector r end-point (1 for each particle)

global Toler_grad

global MAP_RESOLUTION % Alteração introduzida (FEV/2008) p/ permitir utilização de mapas c/ resoluções diferentes de 1m (ver Notas G)

[sigma_alpha, stdm, kstdm, cut_grad, cut_range, K] = ...
    sonar_physic_consts(theta); % Establishes constants used by phsicial/statistical model of sonar

[rw,cl] = size(Xpfp0);
 N      = cl;
%N=length(Xpfp0); % number of points

invalid_depth=Map(1);
invalid_range=invalid_depth;

max_iterations=100;

%[L C] = size(Map)*MAP_RESOLUTION;
%[L C] = size(Map); L=L*MAP_RESOLUTION; C=C*MAP_RESOLUTION;

rho_r = rho - pi/2; % angle of beam relative to the vertical

RM=rotation_matrix1_3Dnoroll(rho_r,psi); % compute rotation matrix parameterized by sonar direction

if rho==pi/2                                    % if sonar beam is vertical
    depths=Map_valid2(Map,Xpfp0(1,:),Xpfp0(2,:));  % measure in the vertical of the sensor
    Xpfr=(depths - z0); % ranges = -mapped_depths - vehicle_depth
    xt=Xpfp0(1,:); yt=Xpfp0(2,:);
end
kxm=Map_valid2(dMap_dx,xt,yt); % obtain array of gradients dM/dx
kym=Map_valid2(dMap_dy,xt,yt); % obtain array of gradients dM/dy
% establish arrays containing all vectors that define the planes tangent to the surface at each reflection point:
gradx=[ones(1,N); zeros(1,N); kxm]; grady=[zeros(1,N); ones(1,N);  kym];
ngradx=RM'*gradx;  ngrady=RM'*grady; % apply rotation matrix to those vectors
substngradx=find(abs(ngradx(1,:)) < Toler_grad); % detect near zero values to avoid division by zero
ngradx(substngradx) = Toler_grad*sign(ngradx(substngradx));
substngrady=find(abs(ngrady(1,:)) < Toler_grad); % detect near zero values to avoid division by zero
ngrady(substngrady) = Toler_grad*sign(ngrady(substngrady));
kx=ngradx(3,:)./ngradx(1,:); ky=ngrady(3,:)./ngrady(2,:); % calculate gradients in new reference frame    
modgrad=sqrt(kx.^2 + ky.^2); % calculate scalar measure of local gradient at each point
ud=K*Xpfr.*exp(-Xpfr/cut_range).*modgrad.*exp(-modgrad/cut_grad); % mean parameter of distribution of measurement error
sd=stdm + kstdm*Xpfr; % std.dev of measurement error
%toc ; iteration  % display time and number of iterations consumed by search and 
%sd = 1;

ud = zeros(size(sd));
if ~deterministic
    Xpfr = Xpfr + ud + randn(1,N).*sd; % add gaussian noise if used for stochastic simulation
end            

%plot_calcmdepths2(Xpfr,Xpfp0,depths,z0,rho) %  to plot the results of this script 