function J = computeCost(X, y, theta)

m = length(y); 
k = X*theta-y;
t = k.*k;
J = sum(t)/(2*m);

end
