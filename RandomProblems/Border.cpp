#include <vector>
#include <iostream>

int main () {
	int t, k;
	std::cin >> t >> k;
	std::vector<std::vector<char>> vec(k ,std::vector<char>(t));
	for (int i = 0;i < k; i++) {
		for (int j = 0; j < t; j++) {
			char w; std::cin >> w;
			vec[i][j] = w;
		}
	}
	long long count = 0;
	for (int i = 0;i < k; i++) {
		for (int j = 0; j < t; j++) {
			if (vec[i][j] == 'B') continue;
			if (i > 0){
				if (vec[i - 1][j] == 'B') count++;
			}
			if (i < k - 1) {
				if (vec[i + 1][j] == 'B') count++;
			}
			if (j < t - 1) {
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
