#include <iostream>
#include <vector>
#include <algorithm>

int main () {
	int a; std::cin >> a;
	std::vector <int> dp(a + 1);
	dp[0] = 0;
	for (int i = 1;i <= a;i ++) {
		dp[i] = i;
		for (int k = 0;k <= i / 2;k++) {
			dp[i] = std::min(dp[i], dp[k] + dp[i - k]);
		}
		for (int k = 2;k * k <= i;k++) {
			if (i % k == 0) {
				dp[i] = std::min(dp[i], dp[k] + dp[i / k]);
			}
		}
	}
	std::cout << dp[a];
	return 0;
}

			

