#include <iostream>

int main () {
	int a, count = 0; std::cin >> a;
	for (int i = 0; i < a; i++) {
		for (int q = 0; q < a; q++) {
			int w; std::cin >> w; count += w;
		}
	}
	std::cout << count / 2;
	return 0;
}
