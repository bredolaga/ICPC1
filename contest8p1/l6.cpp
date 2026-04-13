#include <iostream>
#include <vector>

int main () {
	int a; std::cin >> a;
	std::vector <std::vector<int>> matrix(a, std::vector<int>(a));
	std::vector <int> vec(a);
	for (int i = 0;i < a; i ++) {
		for (int q = 0; q < a; q++) {
			std::cin >> matrix[i][q];
		}
	}

	for (int i = 0; i < a; i++) std::cin >> vec[i];
	
	int count = 0;
	for (int i = 0;i < a; i ++) {
		for (int q = 0; q < a; q++) {
			if (matrix[i][q] != 0 && vec[i] != vec[q]) count ++;
		}
	}

	std::cout << count / 2;
	return 0;
}
