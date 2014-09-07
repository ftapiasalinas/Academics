function [w, Xd, Yd, density] = densityfn_LB(Xpf1,Xpf2,nkde,ppkde,Y,wt,sigmar, plotdensity)

Xd=0;
Yd=0;
density =0;

%%
const_exp = 1./(sigmar*2.50663);

x_xpf2 = Xpf2(1,:);
y_xpf2 = Xpf2(2,:);

% use only the important grid nodes :
Ieff = ( wt(:) > 0.05 * max(wt(:)) );

x_xpf1 = Xpf1(1,Ieff);
y_xpf1 = Xpf1(2,Ieff);
wt = wt(Ieff);



if plotdensity
    MIN_XY1 = [min(Xpf2(1,:)),min(Xpf2(2,:))];
    MAX_XY1 = [max(Xpf2(1,:)),max(Xpf2(2,:))];
    
    MIN_XY =   MIN_XY1 - (MAX_XY1-MIN_XY1).*ppkde;
    MAX_XY =   MAX_XY1 + (MAX_XY1-MIN_XY1).*ppkde;
    [Xd,Yd]=meshgrid(MIN_XY(1):nkde:MAX_XY(1),MIN_XY(2):nkde:MAX_XY(2));
    %% IF you want to plot a mesh of the likelihood for debug:
    parfor kdc = 1 : length(Xd(:))
        rd     = sqrt((x_xpf1 - Xd(kdc)).^2 + (y_xpf1 - Yd(kdc)).^2);
        w(kdc) = max( wt.*const_exp.*exp(-((rd - Y).^2)./(2*(sigmar.^2))));
    end
    density = reshape(w,size(Xd,1),size(Xd,2));
    %%
    w = interp2(Xd,Yd,density, Xpf2(1,:),Xpf2(2,:));
    w(isnan(w)) = 0;
else
    %% Initialize the output weights vector
    w = zeros(1,length(Xpf2(1,:)));
    
    parfor kdc = 1 : length(x_xpf2)
        rd     = sqrt((x_xpf1 - x_xpf2(kdc)).^2 + (y_xpf1 - y_xpf2(kdc)).^2);
        w(kdc) = max( wt.*const_exp.*exp(-((rd - Y).^2)./(2*(sigmar.^2))));
    end
    
end