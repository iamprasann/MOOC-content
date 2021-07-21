#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

#define MY_INT32_MAX 2147483647;

vector<int> optimal_sequence(int n){


    vector<int> counts(n+1);
    counts[0]=0; counts[1]=0;

    vector<int> best_parent(n+1);
    best_parent[0]=0; best_parent[1]=0;

    for(int i=2; i<=n; i++){

        int num_ops=counts[i-1]+1;

        counts[i] = num_ops;
        best_parent[i] = int(i-1);

        if(i%2==0){
            num_ops=counts[i/2]+1;
            if (num_ops<counts[i]){
                counts[i]=num_ops;
                best_parent[i]=(int)(i/2);
            }
        }

        if(i%3==0){
            num_ops=counts[i/3]+1;
            if (num_ops<counts[i]){
                counts[i]=num_ops;
                best_parent[i]=(int)(i/3);
            }
        }
    }

    vector<int> sequence(0);
    sequence.push_back(n);
	int idx = n;
	while (best_parent[idx] > 0)
	{
		sequence.push_back(best_parent[idx]);
		idx = best_parent[idx];
	}

	reverse(sequence.begin(), sequence.end());
    return sequence;
}

vector<int> wrong_optimal_sequence(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        }
        else if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    return 0;
}
