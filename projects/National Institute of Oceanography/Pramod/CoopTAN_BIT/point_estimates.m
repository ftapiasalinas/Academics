function [X_hat,P_hat]=point_estimates(Xpf,w)
% Efficient computation of point estimates for a set of particles
% INPUTS:
%   Xpf = set of particles (PF part of state vector)
%   Xkf = set of particles (KF part of state vector)
%   Pkf = Kalman Filter Covariance matrix P(k|k)
%   w = corresponding set of weights

% wX1=w.*Xpf(1,:); wX2=w.*Xpf(2,:); 
% X_hat=[sum(wX1); sum(wX2)]; % mean(Xi) = sum(wi*Xi) i=1..N
% sum_wX2=[wX1; wX2]*[Xpf(1,:)' Xpf(2,:)'];
% %P_hat(:,:)=sum_wX2 - X_hat*X_hat'; % cov=sum(wi*Xj*Xj')-mean(Xi)*mean(Xi)'
% P_hat = sum_wX2 - X_hat*X_hat'; % cov=sum(wi*Xj*Xj')-mean(Xi)*mean(Xi)'
[m,~]=size(Xpf);
Wx = (ones(m,1)*w).*Xpf;
X_hat = sum(Wx,2);
sum_wX2 = Wx*Xpf';
P_hat(:,:)=sum_wX2 - X_hat*X_hat';

%  wX1=w.*Xpf(1,:); wX2=w.*Xpf(2,:); wX3=w.*Xpf(3,:); wX4=w.*Xpf(4,:); 
%  X_hat=[sum(wX1); sum(wX2); sum(wX3); sum(wX4)]; % mean(Xi) = sum(wi*Xi) i=1..N
%  sum_wX2=[wX1; wX2; wX3; wX4]*[Xpf(1,:)' Xpf(2,:)' Xpf(3,:)' Xpf(4,:)'];
%  P_hat(:,:)=sum_wX2 - X_hat*X_hat'; % cov=sum(wi*Xj*Xj')-mean(Xi)*mean(Xi)'
% % 
