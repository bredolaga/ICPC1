#include <iostream>
#include <vector>
#include <algorithm>

int main () {
	int s, n;
	std::cin >> s >> n;
	std::vector <int> dp (s + 1, 0);
	std::vector <int> w(n), v(n);
	for (int i = 0;i < n;i++) {
		std::cin >> w[i] >> v[i];
	}
	for (int i = 0; i < n; i++){
		for (int weight = w[i]; weight <= s; weight ++) {
			dp[weight] = std::max(dp[weight], dp[weight - w[i]] + v[i]);
		}
	}
	std::cout << dp[s];
	return 0;
}

