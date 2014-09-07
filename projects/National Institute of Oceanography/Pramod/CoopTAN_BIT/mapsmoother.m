function [Zfilt_s] = mapsmoother(Map,filterfreg, resolution)

a= filterfreg;
Dx = resolution;
[X,Y] = size(Map);
Zfilt_s = zeros(X,Y);
for i = 1:Y
    Zfilt= Map(1,i);
    for j = 1: X
        Z1= Map(j,i);
        Zfiltdx = -a*Zfilt + a*Z1;
        Zfilt = Zfilt + Zfiltdx*Dx;
        Zfilt_s(j,i) = Zfilt ;
    end
end
