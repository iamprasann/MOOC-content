#include <iostream>

int gcd_fast(int a, int b){
    return a % b == 0 ? b : gcd_fast(b % a, a);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
