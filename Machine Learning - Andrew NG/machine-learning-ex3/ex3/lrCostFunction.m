function [J, grad] = lrCostFunction(theta, X, y, lambda)
%LRCOSTFUNCTION Compute cost and gradient for logistic regression with 
%regularization
%   J = LRCOSTFUNCTION(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

h=sigmoid(X*theta);
J = (1/m) * (((-1 * y') * log(h)) - ((1-y') * log(1-h))) + (lambda/(2*m)) * (sum(theta(2:end) .^ 2));

temp=theta;
temp(1)=0;

grad=(1/m)*X'*(h-y) + (lambda / m) * temp;

grad = grad(:);

end
