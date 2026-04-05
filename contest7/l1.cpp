#include <iostream>
#include <vector>

int main () {
	int a, b; std::cin >> a >> b;
	std::vector <long long> sums(a + 1);
	long long sum = 0; sums[0] = 0;
	for (int i = 1; i <= a;i ++) { 
		int q;
		std::cin >> q; sum += q;
		sums[i] = sum;
	}

	while (b > 0) {
		int l, r;
		std::cin >> l >> r;
		std::cout << sums[r] - sums[l - 1] << std::endl;
		b--;
	}
	return 0;
}

