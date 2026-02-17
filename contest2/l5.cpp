#include <iostream>
#include <vector>

int main () {
	int l, r, t = 0;
	std::cin >> l >> r;
	std::vector <int> vec(r + 1, true);
	if (r < 2) return 0;
	vec[0] = false; vec[1] = false;
		for (int i = 2;i * i <= r;i++) {
			if (vec[i]) {
				for (int q = i * i;q <= r;q += i) {
					vec[q] = false;
				}
			}
		}
	for (int i = l;i <= r;i++){
		if (vec[i]) {
			if (t != 0) std::cout << " ";
			std::cout << i; t++;
		}
	}
return 0;
}
