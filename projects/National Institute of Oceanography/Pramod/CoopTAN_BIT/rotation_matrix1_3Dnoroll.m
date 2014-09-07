function R=rotation_matrix1_3Dnoroll(theta,psi)
% Calculate the rotation matrix for phi=0 (roll=0) , parameterized by the angles theta and psi:
%   theta = pitch (rad)
%   psi = yaw (rad)

R=[cos(psi)*cos(theta)      -sin(psi)        cos(psi)*sin(theta);
   sin(psi)*cos(theta)      cos(psi)        +sin(theta)*sin(psi);
    -sin(theta)             0                        cos(theta)];

