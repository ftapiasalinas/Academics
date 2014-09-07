function depth=Map_valid(Map,x,y)
% Validates the coordinates x,y verifying if they fall inside the area of the map
% and converting to valid index numbers. If outside the map limits, returns the flag 99999 
% Executes bi-linear interpolation to obtain the depth from the Map. This assumes that the surface connecting the 4 neighbour points
% surrounding (x,y) can be approximated by a plane and the error associated to this approximation is negligible.
%   Map is a matrix representing the map;
%   x, y are coordinates in the intervals [0:L], and [0:C].

global MAP_RESOLUTION % Alteração introduzida (FEV/2008) p/ permitir utilização de mapas c/ resoluções diferentes de 1m (ver Notas G)

invalid_depth=99999;

x=x/MAP_RESOLUTION; y=y/MAP_RESOLUTION; 

[L C]=size(Map);
if x<0 | (x+1)>L | y<0 | (y+1)>C
    depth=invalid_depth; % flag: depth not valid 
else
    if fix(x)==x & fix(y)==y
        depth = Map(x+1,y+1); % interpolation not necessary
    else
        % obtain coordinates of surrounding mapped points:
        p1x=fix(x);   p2x=fix(x+1); 
        p1y=fix(y);   p3y=fix(y+1);
        % obtain values of surrounding mapped points:
        h1=Map(p1x,p1y); h2=Map(p2x,p1y); h3=Map(p1x,p3y); h4=Map(p2x,p3y); 
        d1=x-p1x; d2=y-p1y; 
        % Interpolate:
        % depth = h1*(1-d2/d) + (h2-h1)*(d1-d2*d1/d)/d + h3*(d2-d2*d1/d)/d + h4*d1*d2/d/d;
        % map resolution d=1 simplifies the calculations:
        depth = h1*(1-d2) + (h2-h1)*(d1-d2*d1) + h3*(d2-d2*d1) + h4*d1*d2;   % bi-linear interpolation
    end
end
