function G=GuU_gps(U,sd_vx,sd_vy,N)
% Calculates the product of the time-varying input-coupling matrix G(U(t)) by the input vector U(t)
% for the case of a vehicle stabilized in pitch and roll :only yaw and yaw rate vary (see script sim_nav.m)
% G is a function only of psi=U(3) and r=U(4), and multiplies only the elements Vu=U(1) and Vv=U(2)
% INPUTS: 
%   U = [Vu; Vv; psi; r; z]
%   sd_psi = standard dev. of yaw noise in discrete time model (rad)
%   sd_psirate = standard dev. of yaw rate noise in discrete time model (rad/sec)
%   N = number of particles = number of columns in matrix G (2xN)
% OUTPUT:
%   G = 2xN matrix containing the input velocity vector U(1:2) transformed from the vehicle frame to the inertial frame 
%       with rand.error added to the yaw and yaw rate input parameters for each particle.

Vx=U(1) + randn(1,N)*sd_vx; % add errors to psi input
Vy=U(2) + randn(1,N)*sd_vy; % add errors to psi-rate input
G=[Vx;Vy];

