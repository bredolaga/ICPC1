#include <iostream>
#include <vector>
#include <cmath>

long long func(int fc,int power, int mod) {
	if (power == 0) return 1%mod;
	long long result = func(fc,power / 2, mod);
	result = (result * result) % mod;
	if (power % 2 == 1) result = (result * fc) % mod;
	return result;
}


int main () {
	int a, b, mod = 9929;
	std::cin >> a >> b;
	std::vector <int> fc(a + 1);
	std::vector <int> rev(a + 1);
	fc[0] = 1; fc[1] = 1; rev[0] = 1;
	for (int i = 2;i <= a;i ++) {
		fc[i] = (fc[i - 1] * i) % mod;
	}
	for (int i = 1; i <= a; i++) {
		 rev[i] = func(fc[i], mod - 2, mod);
	}
	std::cout << (1LL * fc[a] * rev[b] * rev[a - b]) % mod;
	return 0;
}

