#include <iostream>
#include <vector>

int main () {
	long long mod = 1000000007;
	int a; std::cin >> a;
	std::vector <long long> dp(a + 1);
	dp[0] = 1; dp[1] = 1;
	for (int i = 2;i <= a;i ++) {
		dp[i] = (dp[i] + dp[i - 1]) % mod;
		dp[i] = (dp[i] + dp[i - 2]) % mod;
		if (i > 2) dp[i] = (dp[i] + dp[i - 3]) % mod;
		if (i > 3) dp[i] = (dp[i] + dp[i - 4]) % mod;
		if (i > 4) dp[i] = (dp[i] + dp[i - 5]) % mod;
		if (i > 5) dp[i] = (dp[i] + dp[i - 6]) % mod;
	}
	std::cout << dp[a] % mod;
	return 0;
}
