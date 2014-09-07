function z_values=Map_valid2(Map,xl,yl)
% ATENÇÃO: Corrigida em 28/2/2008 (ver comentários no código)
%   ? Com esta correcção deixa de ser necessário subtrair os bias Bias_pos_x e
%   Bias_pos_y nos cálculos do "estimation error at run k" ?
%
% Validate and interpolate z values at coordinates specified in vectors x and y:
% INPUTS:
%   Map = bathymetric map, or other map such that z=f(x,y)
%   x, y = vectors of real coordinates in the intervals [0:L], and [0:C]
% OUTPUT:
%   z_values = values of Map at the coordinates specified in x, y
% Validates the coordinates x,y verifying if they fall inside the area of the map
% and converting to valid index numbers. 
% All invalid coordinates are transformed to the coordinates (1,1) and the linear coordinate (1)
% which is useful if the matrix M contains a flag value at position (1,1), ex: M(1,1)=9999

% Executes bi-linear interpolation to obtain the depth from the Map.

% (version based on Map_valid.m and valid_coordinates.m )


global MAP_RESOLUTION % Alteração introduzida (FEV/2008) p/ permitir utilização de mapas c/ resoluções diferentes de 1m (ver Notas G)
x=xl/MAP_RESOLUTION; y=yl/MAP_RESOLUTION; 

invalid_value=Map(1);

[L C] = size(Map);

notvalidx=find(x<0 | (x+2)>=L);
notvalidy=find(y<0 | (y+2)>=C);


x=x+1;y=y+1;
%notvalid = union(notvalidx,notvalidy);
x(notvalidx)=1;y(notvalidx)=1;
x(notvalidy)=1;y(notvalidy)=1;

% obtain coordinates of surrounding mapped points:
% p1x=fix(x)+1; p2x=fix(x+1)+1; 
% p1y=fix(y)+1; p3y=fix(y+1)+1;
p1x=fix(x); p2x=fix(x+1); % (Corrigida em 28/2/2008)
p1y=fix(y); p3y=fix(y+1);
% obtain z_values of surrounding mapped points:
h1=Map(sub2ind([L C],p1x,p1y)); 
h2=Map(sub2ind([L C],p2x,p1y)); 
h3=Map(sub2ind([L C],p1x,p3y)); 
h4=Map(sub2ind([L C],p2x,p3y)); 
% d1=x+1-p1x; d2=y+1-p1y;
d1=x-p1x; d2=y-p1y; % (Corrigida em 28/2/2008)
z_values = h1.*(1-d2) + (h2-h1).*(d1-d2.*d1) + h3.*(d2-d2.*d1) + h4.*d1.*d2;   % bi-linear interpolation
z_values(notvalidx)=invalid_value; z_values(notvalidy)=invalid_value;
