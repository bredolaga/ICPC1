#include <iostream>
#include <vector>

int main () {
	int a, b;
	std::cin >> a >> b;
	std::vector <int> vec(1001);
	for (int i = 0; i < b;i++) {
		int x, y; std::cin >> x >> y;
		vec[x] ++;
		vec[y] ++;
	}
	int count = 0;
	for (auto x : vec) {
		if (x == 1) count ++;
	}
	std::cout << count;
	return 0;
}
