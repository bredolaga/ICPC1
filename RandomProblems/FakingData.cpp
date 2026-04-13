#include <iostream>
#include <vector>
#include <algorithm>

int main () {
	long long a; std::cin >> a;
	std::vector <int> vec1(a);
	std::vector <int> vec2(a);
	if (a == 0) {
		std::cout << 0;
		return 0;
	}

	for (int i = 0; i < a;i ++) {
		int q; std::cin >> q;
		vec1[i] = q;
		vec2[i] = q;
	}

	long long count1 = 0, count2 = 0;
	for (int i = 0; i < a; i++) {
		if (i % 2 == 0) {
			if (i > 0 && vec1[i] >= vec1[i - 1]) {
				int num = vec1[i] - vec1[i - 1] + 1;
				vec1[i] -= num;
				count1 += num;
			}
			if (i < a - 1 && vec1[i] >= vec1[i + 1]) {
				int num = vec1[i] - vec1[i + 1] + 1;
				vec1[i] -= num;
				count1 += num;
			}
		}
		if (i % 2 == 1) {
			if (i > 0 && vec2[i] >= vec2[i - 1]) {
				int num = vec2[i] - vec2[i - 1] + 1;
				vec2[i] -= num;
				count2 += num;
			}
			if (i < a - 1 && vec2[i] >= vec2[i + 1]) {
				int num = vec2[i] - vec2[i + 1] + 1;
				vec2[i] -= num;
				count2 += num;
			}
		}
	}
	std::cout << std::min(count1, count2);
	return 0;
}
