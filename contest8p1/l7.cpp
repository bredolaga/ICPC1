#include <iostream>
#include <vector>

int main () {
	int a; std::cin >> a;
	std::vector <std::vector<int>> vec(a, std::vector<int>(a));
	for (int i = 0; i < a; i ++){
		for (int q = 0; q < a; q++) std::cin >> vec[i][q];
	}
	for (int i = 0; i < a;i++) {
		for (int q = i; q < a; q++) {
			if (vec[i][q] == 1) std::cout << i + 1 << " " << q + 1 << '\n';
		}
	}
			
	return 0;
}

