#include <iostream>
#include <vector>

long long func (long long num, long long pow, long long mod) {
	if (pow == 0) return 1;
	long long result = func(num, pow / 2, mod);
	result = result * result % mod;
	if (pow % 2 == 1) result = result * num % mod;
	return result;
}


int main () {
	long long mod = 1000000007;
	int m, n; std::cin >> n >> m;
	std::vector <long long> fc(m + n + 1), rev(m + n + 1);
	fc[0] = 1; rev[0] = 1;
	for (int i = 1; i <= m + n;i ++) {
		fc[i] = (fc[i - 1] * i) % mod;
	}
	rev[m] = func(fc[m], mod - 2, mod);
	rev[n - 1] = func(fc[n - 1], mod - 2, mod);
	std::cout << 1LL * fc[m + n - 1] % mod * rev[m] % mod * rev[n - 1] % mod;
	return 0;
}
