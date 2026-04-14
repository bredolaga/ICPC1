#include <vector>
#include <iostream>

std::vector <std::vector<int>> vec;
std::vector <int> ver;
int a;

bool find (int x) {
	ver[x] = 1;
	for (int i = 0; i < a; i++) {
		if (vec[x][i] == 0) continue;

		if (ver[i] == 1) return true;
		if (ver[i] == 0 && find(i)) return true;
	}
	ver[x] = 2;
	return false;
}

int main () {
	std::cin >> a;
	vec.resize(a, std::vector<int>(a));
	ver.resize(a, 0);
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			std::cin >> vec[i][j];
		}
	}

	for (int i = 0; i < a; i ++) {
		if (ver[i] == 0) {
			if (find(i)) {
				std::cout << 1;
				return 0;
			}
		}
	}
	std::cout << 0;
	return 0;
}
