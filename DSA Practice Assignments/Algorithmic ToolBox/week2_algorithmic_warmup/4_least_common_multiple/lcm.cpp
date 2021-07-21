#include <iostream>

int gcd_fast(int a, int b){
    return a % b == 0 ? b : gcd_fast(b % a, a);
}

long long lcm_fast(long long a, long long b) {
    return a*b/gcd_fast(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

