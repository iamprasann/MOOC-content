function g = sigmoid(z)
	k=size(z);
for i=1:k(1);
	for j=1:k(2);
		g(i,j)=1/(1+exp(-z(i,j)));
	end
end
end
