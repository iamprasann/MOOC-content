function [J, grad] = linearRegCostFunction(X, y, theta, lambda)
%LINEARREGCOSTFUNCTION Compute cost and gradient for regularized linear 
%regression with multiple variables
%   [J, grad] = LINEARREGCOSTFUNCTION(X, y, theta, lambda) computes the 
%   cost of using theta as the parameter for linear regression to fit the 
%   data points in X and y. Returns the cost in J and the gradient in grad

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

t2=(X*theta-y);
t3=theta;
t3(1)=0;
J=J+(1/(2*m))*(t2'*t2)+(lambda/(2*m))*(t3'*t3);

grad=grad+((1/m)*(t2'*X)')+((lambda/m)*(t3));
grad = grad(:);

end
