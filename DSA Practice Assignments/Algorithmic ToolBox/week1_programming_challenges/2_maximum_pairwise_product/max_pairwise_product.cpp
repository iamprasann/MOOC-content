#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int MaxPairwiseProduct(const vector<int>& numbers) {
    int max1=0, max2=0, index=0;
    long long int max_product=0;
    int n = numbers.size();

    for(int i=0; i<n; i++){
    		if(numbers[i]>max1){
    			max1=numbers[i];
    			index=i;
    		}
    }

    for(int i=0; i<n; i++){
    		if(numbers[i]>max2 && i!=index){
    			max2=numbers[i];
    		}
    }

    max_product=(long long int)max1*max2;

    return max_product;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}