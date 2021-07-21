#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
    double value = 0.0;
    int n = weights.size();

    vector< pair<double, double> > value_per_unit;
    for (int i = 0; i < n; i++) {
        value_per_unit.push_back(make_pair(values[i] / weights[i], weights[i]));
    }
    sort(value_per_unit.begin(), value_per_unit.end());

    int i = n - 1;
    double temp_value;
    while (capacity > 0.0 && i >= 0) {
        if (value_per_unit[i].second >= capacity) {
            value += (value_per_unit[i].first * capacity);
            capacity = 0.0;
            break;
        } else {
            value += (value_per_unit[i].first * value_per_unit[i].second);
            capacity -= value_per_unit[i].second;
        }
        i--;
    }

    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
