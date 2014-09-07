function R=rotation_matrix_2D(psi)
% Calculate the 2D rotation matrix for phi=0 (roll=0) , parameterized by the angle psi (expressed in rad):
%   psi = yaw 

% disp('ATTENTION (rotation_matrix_3Dnoroll) angles assumed in rad.')

R=[cos(psi)     -sin(psi);
   sin(psi)      cos(psi)];

