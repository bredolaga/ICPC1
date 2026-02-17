#include <iostream>

int main () {
	int t; std::cin >> t;
	while (t-- > 0) {
		int sum, start, size;
		bool flag = false;
		std::cin >> sum;
		for (long long i = 2;i * (i + 1) <= 2LL * sum;i++) {
			int q = ((2 * sum) / i) - i + 1; // 2sum
			if (q < 1) continue;
			if ((2 * sum) % i != 0) continue;
			if (q % 2 != 0) continue;
			size = i; flag = true;
			start = q / 2;
			break;
		}
	if (!flag) std::cout << "IMPOSSIBLE" << std::endl;
	else {
	std::cout << sum << " = ";
	for (int i = start; i < start + size - 1;i++) { 
		std::cout << i << " + ";
	}
	std::cout << start + size - 1 << std::endl;
	}
}
return 0;
}
