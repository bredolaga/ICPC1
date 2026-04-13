#include <iostream>
#include <vector>

int main () {
	int a, b;
	std::cin >> a >> b;
	if (a * (a - 1) < b) {
		std::cout << "YES";
		return 0;
	}
	std::vector <std::pair<int, int>> vec;
	for (int i = 0; i < b; i++) {
		int q, w; std::cin >> q >> w;
		vec.push_back({q, w});
	}
	for (int i = 0; i < b; i++) {
		for (int q = i + 1; q < b; q++) {
			if (vec[i] == vec[q]) {
				std::cout << "YES";
				return 0;
			}
		}
	}
	std::cout << "NO";
	return 0;
}

