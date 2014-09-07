function pe=likely(Y,f_Xpf,ud,sd)
% calculates likelihood function p(Y|X) for a set of values
% Y = scalar measurement
% f_Xpf = (1xN) array of values defined as a function of the set of state vectors [x ; y]
% ud, sd = (1xN) arrays of distribution parameters 
% pe = 1xN array of likelihood values

global invalid_depth

iidx = f_Xpf == -invalid_depth;
pe=exp(-((Y - f_Xpf - ud).^2)./(2*(sd.^2)))./(sd*2.50663); % (1/sd*sqrt(2*pi))*exp(-0.5*(yk-f(Xpf)-ud)^2/sd^2)
pe(find(isnan(pe)))=0;
pe(iidx)=0;
