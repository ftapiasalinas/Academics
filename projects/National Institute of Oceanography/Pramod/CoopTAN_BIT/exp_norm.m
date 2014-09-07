function pe=exp_norm(X,muX,P)
% calculates multivariable exponential part of gaussian function
% X = array (KxN) of x
% muX = array (KxN) of expected values of x
% P = covariance matrix (KxK)
% pe = 1xN array of exp (X(i)'*inv(P)*X(i)) values
pe=exp(-0.5*diag((X-muX)'*inv(P)*(X-muX)))'; 

