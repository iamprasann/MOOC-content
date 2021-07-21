#include <iostream>
#include <vector>

using namespace std;

#define MY_INT32_MAX 2147483647;

int get_change(const int money, const vector<int>& coins) {

	int NumCoins = 0;
	vector<int> min_coins(int(money/coins[0])+1);
	min_coins[0] = 0;

	for (size_t m = 1; m <= money; m++)
	{
		min_coins[m] = MY_INT32_MAX;

		for (auto c:coins)
		{
			if (m >= c) {
				NumCoins = min_coins[(m - c)] + 1;
				if (NumCoins < min_coins[m])
					min_coins[m] = NumCoins;
			}
		}
	}
	return min_coins[money];
}

int main() {

    int money;
    std::cin >> money;

    vector<int> coins={1, 3, 4};

    std::cout << get_change(money, coins) << '\n';

}
