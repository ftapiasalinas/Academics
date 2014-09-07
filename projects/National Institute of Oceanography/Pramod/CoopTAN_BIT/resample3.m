function p=resample3(w,N)
% Resampling method 3 (see script test_resample.m)
% Samples N particles uniformly, from a set of M particles (M >= N)
% w = set of normalized weigths of particles
% N = number of particles to be sampled
% p = indexes of the new set of particles
% tic
M=length(w);
k=1;
for j=1:M
    np=round(w(j)*M); % number of times the particle will be resampled is proportional to its weight
    p(k:k+np-1)=j;      % it works even with np=0
    k=k+np;
end  
if k<=M
    % not enough particles: fill randomly the remaining positions using the already selected particles
    % p(k:M)=p(fix(rand(1,M-k+1)*M+1));
    % or, alternatively:
    M=k-1; % since k approx=M, sample from set of k-1 particles 
end   
ind=fix(rand(1,N)*(M-1)+1);
p=p(ind); % sample N new particle indexes randomly from p
% t3=toc

