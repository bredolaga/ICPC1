#include <iostream>
#include <cmath>

int main() {
	int a; std::cin >> a;
	if (a == 1) {
		std::cout << 1;
		return 0;
	}
	int q = sqrt(a),count = 0;
	for (int i = 1; i <= q;i++) {
		if (a % i == 0) {
			if (a / i > q) count += 2;
			else count ++;
		}
	}
	std::cout << count- 2;
	return 0;
}
