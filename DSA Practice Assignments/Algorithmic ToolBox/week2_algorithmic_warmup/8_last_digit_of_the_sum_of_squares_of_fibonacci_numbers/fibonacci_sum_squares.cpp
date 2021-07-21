#include <iostream>

int fibonacci_sum_squares(long long n){
        if(n<0)
            return 0;
        int remainders[]={0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1};
        int index=n%60;
        int sum=0;
        for(int i=0; i<=index; i++)
            sum+=remainders[i]*remainders[i];

        return sum%10;
    }

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
