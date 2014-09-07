function h=error_ellipse2D(C,mu,conf,scale,varargin)
% ERROR_ELLIPSE - plot an error ellipse defining confidence region
%    Given a 2x2 covariance matrix, plot the
%    associated error ellipse, at the origin. It returns a graphics handle
%    of the ellipse that was drawn.
%    Plot the ellipse, centered at MU, a vector whose length should match that of C 
% INPUTS:
%    C = the covariance matrix
%    mu = the mean vector representing the ellipse center
%    conf = value betwen 0 and 1 specifying the confidence interval.
%        the default is 0.5 which is the 50% error ellipse.
%    scale = allow the plot the be scaled to difference units.
%
%    NOTES: C must be positive definite for this function to work properly.


if conf <= 0 | conf >= 1
  error('conf parameter must be in range 0 to 1, exclusive')
end

[r,c] = size(C);
if r ~= c | (r ~= 2)
  error(['Don''t know what to do with ',num2str(r),'x',num2str(c),' matrix'])
end

y0=mu(1);
x0=mu(2);

% Compute quantile for the desired percentile
k = sqrt(qchisq(conf,r)); % r is the number of dimensions (degrees of freedom)

%hold_state = get(gca,'nextplot');

% Make the matrix has positive eigenvalues - else it's not a valid covariance matrix!
[eigvec,eigval] = eig(C); % Compute eigen-stuff
eigC=[eigval(1,1);eigval(2,2)];

if any(eigC <=0)
    error('The covariance matrix must be positive definite (it has non-positive eigenvalues)')
end

[x,y] = getpoints(C,eigvec,eigval);
if length(varargin)
    % a handle has been passed to the function: use it to plot the ellipse
    h1=varargin{1};
    set(h1,'XData',scale*(x0+k*x),'YData',scale*(y0+k*y));
    drawnow
else
    % create a graphics handle to the ellipse
%     h1=plot(scale*(y0+k*y),scale*(x0+k*x),'-k');
    h1=plot(scale*(x0+k*x),scale*(y0+k*y),'-k','LineWidth',2);
%    legend(h1,'3 \sigma covariance');
    set(h1,'EraseMode','xor'); 
end
%set(h1,'zdata',z+1)
if nargout
    h=h1;
end
%axis equal

%set(gca,'nextplot',hold_state);

%---------------------------------------------------------------
% getpoints - Generate x and y points that define an ellipse, given a 2x2
%   covariance matrix, C. z, if requested, is all zeros with same shape as
%   x and y.
function [x,y] = getpoints(C,eigvec,eigval)

n=100; % Number of points around ellipse
p=0:pi/n:2*pi; % angles around a circle

xy = [cos(p'),sin(p')] * sqrt(eigval) * eigvec'; % Transformation
x = xy(:,1);
y = xy(:,2);


%---------------------------------------------------------------
function x=qchisq(P,n)
% QCHISQ(P,N) - quantile of the chi-square distribution.
if nargin<2
  n=1;
end

s0 = P==0;
s1 = P==1;
s = P>0 & P<1;
x = 0.5*ones(size(P));
x(s0) = -inf;
x(s1) = inf;
x(~(s0|s1|s))=nan;

for ii=1:14
  dx = -(pchisq(x(s),n)-P(s))./dchisq(x(s),n);
  x(s) = x(s)+dx;
  if all(abs(dx) < 1e-6)
    break;
  end
end

%---------------------------------------------------------------
function F=pchisq(x,n)
% PCHISQ(X,N) - Probability function of the chi-square distribution.
if nargin<2
  n=1;
end
F=zeros(size(x));

if rem(n,2) == 0
  s = x>0;
  k = 0;
  for jj = 0:n/2-1;
    k = k + (x(s)/2).^jj/factorial(jj);
  end
  F(s) = 1-exp(-x(s)/2).*k;
else
  for ii=1:numel(x)
    if x(ii) > 0
      F(ii) = quadl(@dchisq,0,x(ii),1e-6,0,n);
    else
      F(ii) = 0;
    end
  end
end

%---------------------------------------------------------------
function f=dchisq(x,n)
% DCHISQ(X,N) - Density function of the chi-square distribution.
if nargin<2
  n=1;
end
f=zeros(size(x));
s = x>=0;
f(s) = x(s).^(n/2-1).*exp(-x(s)/2)./(2^(n/2)*gamma(n/2));
