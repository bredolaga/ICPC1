#include <iostream>

long long modpow(long long num, long long pow, long long mod) {
	if (pow == 0) return 1 % mod;
	long long u = modpow(num, pow / 2, mod);
	u = u * u % mod;
	if (pow % 2 == 1) u = (u * num) % mod;
	return u;
}

int main () {
	long long num, pow, mod = 9929;
	std::cin >> num >> pow;
	std::cout << modpow(num , pow , mod);
	return 0;
}
