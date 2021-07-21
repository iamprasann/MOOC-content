#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    int temp=(n+1)%60;

    if(temp==0)
        return 0;

    int a=0, b=1, c=0, sum=1;
    for(int i=0; i<temp-1; i++){
        c=a+b;
        a=b;
        b=c;
        sum+=c;}

    return sum%10;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
