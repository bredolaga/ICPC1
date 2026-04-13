#include <iostream>

int main () {
	int a; std::cin >> a;
	int count = 0;
	for (int i = 0; i < a; i ++) {
		for (int q = 0; q < a; q ++) {
			int w; std::cin >> w; count += w;
		}
	}
	std::cout << count;
	return 0;
}
