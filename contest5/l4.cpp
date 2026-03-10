#include <iostream>
#include <vector>

long long func(long long num, long long pow, long long mod) {
	if (pow == 0) return 1;
	long long result = func(num, pow / 2,mod);
	result = result * result % mod;
	if (pow % 2 == 1) result = result * num % mod;
	return result;
}

int main () {
	long long mod = 1000000007;
	int k; std::cin >> k;
	std::vector <int> colors(k);
	std::vector <long long>  ans(k), fc(1000001);
	fc[0] = 1;
	for (int i = 0;i < k;i++) std::cin >> colors[i];
	for (int i = 1;i <= 1000000;i++) {
		fc[i] = fc[i - 1] * i % mod;
	}
	long long len = colors[0]; ans[0] = 1;
	for (int i = 1;i < k;i++) {
		ans[i] = fc[len + colors[i] - 1] % mod * func(fc[colors[i] - 1], mod - 2, mod) % mod * func(fc[len], mod - 2, mod) % mod * ans[i - 1]  % mod;
		len += colors[i];
	}
	std::cout << ans[k - 1];
	return 0;
}
	
