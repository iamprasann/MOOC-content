function [J, grad] = cofiCostFunc(params, Y, R, num_users, num_movies, ...
                                  num_features, lambda)
%COFICOSTFUNC Collaborative filtering cost function
%   [J, grad] = COFICOSTFUNC(params, Y, R, num_users, num_movies, ...
%   num_features, lambda) returns the cost and gradient for the
%   collaborative filtering problem.
%

% Unfold the U and W matrices from params
X = reshape(params(1:num_movies*num_features), num_movies, num_features);
Theta = reshape(params(num_movies*num_features+1:end), ...
                num_users, num_features);

            
% You need to return the following values correctly
J = 0;
X_grad = zeros(size(X));
Theta_grad = zeros(size(Theta));

k=(X*Theta'-Y).*R;
J=0.5*sum(sum(k.*k));

X_grad=k*Theta;
Theta_grad=k'*X;

J=J+(lambda/2)*sum(sum(Theta.*Theta))+(lambda/2)*sum(sum(X.*X));

X_grad=X_grad+lambda*X;
Theta_grad=Theta_grad+lambda*Theta;

grad = [X_grad(:); Theta_grad(:)];

end
