#include <iostream>
#include <vector>

int main () {
	int a;
	std::cin >> a;
	std::vector <std::vector<int>> vec(a, std::vector<int>(a));
	for (int i = 0;i < a; i++) {
		for (int j = 0; j < a; j++) {
			std::cin >> vec[i][j];
		}
	}

	for (int i = 0;i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (vec[i][j] == 1) std::cout << i + 1 << " " << j + 1 << '\n';
		}
	}

	return 0;
}
