function [Xd, Yd, density] = densityfn_polar(Xpf1,xcc,ycc,minmaxr,minmaxth,nkdr,nkdth,Y,wt,sigmar)


%     nkdr  = 0.1;
%     nkdth = pi/200;
density =0;
MIN_R    = minmaxr(1);
MAX_R    = minmaxr(2);
MIN_TH   = minmaxth(1);
MAX_TH   = minmaxth(2);

[RR,TH]=meshgrid(MIN_R:nkdr:MAX_R,MIN_TH:nkdth:MAX_TH);

[Xd,Yd] = pol2cart(TH,RR);
% 
% Xd = Xd+xcc;
% Yd = Yd+ycc;
% x_xpf1 = Xpf1(1,:);
% y_xpf1 = Xpf1(2,:);
% density = zeros(size(Xd));
% %density = zeros([size(Xd) length(Xpf1)]);
% const_exp = 1./(sigmar*2.50663);
% 
% % hypothesis : 1. There is a correlation between the prior weights of
% % Vehicle 1 (wt) and updated weights after the measurement from vehicle 2,
% % because of this there is an overconfidency problem see paper Fox and
% % thrun 2000, collaborative localization
% overconfidence = 0;
% %Zd = zeros([size(Xd) length(Xpf1)]);
% %%
% if ~overconfidence
%     wt = ones(1,length(Xpf1));
% end
% 
% parfor kdc= 1:length(Xpf1)
%     Zd = sqrt((Xd-x_xpf1(kdc)).^2 + (Yd-y_xpf1(kdc)).^2);
%     density = density + wt(kdc).*const_exp.*exp(-((Zd - Y).^2)./(2*(sigmar.^2)));%%.*(exp(-((Zd - Y).^2)*0.5*sigmar.^2)./(sigmar*2.50663));    
% end
% %sum_density = sum(density,3);
% 
% 
% 
