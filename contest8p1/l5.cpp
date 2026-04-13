#include <iostream>
#include <vector>

int main () {
	int a, b;
	std::cin >> a >> b;
	std::vector <int> in(a, 0), out(a, 0);
	for (int i = 0; i < b; i++) {
		int x, y; std::cin >> x >> y;
		in[y - 1]++; out[x - 1]++;
	}
	for (int i = 0; i < a; i ++) {
		std::cout << in[i] << " " << out[i] << '\n';
	}
	return 0;
}

