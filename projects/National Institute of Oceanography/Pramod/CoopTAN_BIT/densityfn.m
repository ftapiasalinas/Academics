function [w, Xd, Yd, density] = densityfn(Xpf1,Xpf2,nkde,ppkde,Y,wt,sigmar)

    MIN_XY1 = [min(Xpf2(1,:)),min(Xpf2(2,:))];
    MAX_XY1 = [max(Xpf2(1,:)),max(Xpf2(2,:))];
    
    MIN_XY =   MIN_XY1 - (MAX_XY1-MIN_XY1).*ppkde;
    MAX_XY =   MAX_XY1 + (MAX_XY1-MIN_XY1).*ppkde;
    [Xd,Yd]=meshgrid(MIN_XY(1):nkde:MAX_XY(1),MIN_XY(2):nkde:MAX_XY(2));
    %toc
    %Zd = sqrt((Xd-X_hat(1,o)).^2 + (Yd-X_hat(2,o)).^2);
    %density = exp(-(Zd-Y(2,o)).^2/20/sigmar.^2);
    density = zeros(size(Xd));
    const_exp = 1./(sigmar*2.50663);
    
    Ieff = ( wt(:) > 0.05 * max(wt(:)) );
    
    x_xpf1 = Xpf1(1,:);
    y_xpf1 = Xpf1(2,:);
    
    parfor kdc= 1:length(Xpf1)
        Zd     = sqrt((Xd-x_xpf1(kdc)).^2 + (Yd-y_xpf1(kdc)).^2);
        density = density + wt(kdc).*const_exp.*exp(-((Zd - Y).^2)./(2*(sigmar.^2)));%%.*(exp(-((Zd - Y).^2)*0.5*sigmar.^2)./(sigmar*2.50663));                                      
    end
    %    
    
    w = interp2(Xd,Yd,density, Xpf2(1,:),Xpf2(2,:));
    w(isnan(w)) = 0;
    