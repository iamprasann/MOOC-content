#include <iostream>

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m){
    long long reduced=n%get_pisano_period(m);
    long long a=0, b=1, c=reduced;
    for(int i=0; i<reduced-1; i++){
        c=(a+b)%m;
        a=b;
        b=c;}
    return c%m;
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}



