#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int left, int right, int x) {
	if (left > right)
		return - 1;
	int mid = left + int((right - left) / 2);
	if (a[mid] == x)
		return mid;
	else if (a[mid] < x)
		binary_search(a, mid + 1, right, x);
	else
		binary_search(a, left, mid - 1, x);
}


int binary_search_wrapper(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;
  return binary_search(a, left, right, x);

}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search_wrapper(a, b[i]) << ' ';
  }
  return 0;
}
