#include <iostream>
#include <vector>

int main () {
	int a, b;
	std::cin >> a >> b;
	std::vector <std::vector<int>> vec(a, std::vector<int> (a));
	while(b--) {
		int x, y;
		std::cin >> x >> y;
		vec[x - 1][y - 1]++;
	}
	for (int i = 0; i < a; i++) {
		if (i != 0) std::cout << std::endl;
		for (int j = 0; j < a; j++) {
			std::cout << vec[i][j] << " ";
			}
		}
	return 0;
}

