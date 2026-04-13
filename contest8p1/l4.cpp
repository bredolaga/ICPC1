#include <iostream>
#include <vector>

int main () {
	int a, b;
	std::cin >> a >> b;
	std::vector <int> vec(a, 0);
	for (int i = 0; i < b; i++) {
		int x, y; std::cin >> x >> y; 
		vec[x - 1]++; vec[y - 1]++;
	}
	for (auto x : vec) {
		std::cout << x << '\n';
	}
	return 0;
}
