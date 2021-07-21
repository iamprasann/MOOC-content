#include <iostream>
#include <vector>

using std::vector;

int optimal_weight_naive(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight_dp(int W, const vector<int> &wi) {

	vector<vector<int>> opt_value(W + 1, vector<int>(wi.size() + 1));

	for (size_t i = 0; i < W+1; i++)
		opt_value[i][0] = 0;
	for (size_t j = 0; j < wi.size() + 1; j++)
		opt_value[0][j] = 0;

	for (size_t i = 1; i < wi.size() + 1; i++) {
		for (size_t w = 1; w < W + 1; w++)
		{
			int val_pos1 = opt_value[w][i - 1];

			int val_pos2 = 0;
			if (w >= wi[i-1]) {
				val_pos2 = opt_value[w - wi[i-1]][i - 1] + wi[i-1];
			}
			opt_value[w][i] = (val_pos1 > val_pos2) ? val_pos1 : val_pos2;

		}
	}
	return opt_value[W][wi.size()];
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> wi(n);
  for (int i = 0; i < n; i++) {
    std::cin >> wi[i];
  }
  std::cout << optimal_weight_dp(W, wi) << '\n';
}
