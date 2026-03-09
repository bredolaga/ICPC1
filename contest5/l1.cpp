#include <iostream>
#include <vector>
#include <cmath>

int main () {
	int a, b;
	long long mod = 9929;
	std::cin >> a >> b;
	std::vector <long long> vec(a + 1);
	std::vector <long long> rev(a + 1);
	vec[0] = 1; rev[0] = 1;
	for (int i = 1; i <= a; i++) {
		vec[i] = vec[i - 1] * i % mod;
	}
	for (int i = 1; i <= a; i++) {
		rev[i] = std::binpow(vec[i], mod-2);
	}
	long long answer;
	answer = vec[a] * rev[a - b] * rev[b] % mod;
	std::cout << answer;
	return 0;
}
