function [J, grad] = costFunction(theta, X, y)

h=sigmoid(X*theta);
J=0;
m=length(y);
for i=1:m
	J = J-((y(i)*log(h(i))+(1-y(i))*log(1-h(i)))/m);
end

grad = zeros(size(theta));
grad = (1/m)*((h-y)'*X);

end
