#include <vector>
#include <iostream>

int main () {
	int a, b;
	std::cin >> a >> b;
	std::vector<std::vector<char>> vec(b ,std::vector<char>(a));
	for (int i = 0;i < b; i++) {
		for (int j = 0; j < a; j++) {
			char w; std::cin >> w;
			vec[i][j] = w;
		}
	}
	long long count = 0;
	for (int i = 0;i < b; i++) {
		for (int j = 0; j < a; j++) {
			if (vec[i][j] == 'B') continue;
			if (i > 0){
				if (vec[i - 1][j] == 'B') count++;
			}
			if (i < b - 1) {
				if (vec[i + 1][j] == 'B') count++;
			}
			if (j < a - 1) {
				if (vec[i][j + 1] == 'B') count++;
			}
			if (j > 0) {
				if (vec[i][j - 1] == 'B') count++;
			}
		}
	}
	std::cout << count;
	return 0;
}
