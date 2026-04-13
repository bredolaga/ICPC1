#include <iostream>
#include <vector>
#include <queue>

int main () {
	int a; std::cin >> a;
	std::vector <std::vector<int>> vec(a, std::vector<int>(a));
	std::queue <int> que1, que2;
	for (int i = 0; i < a; i++) {
		for (int j =0 ; j < a; j++) {
			std::cin >> vec[i][j];
		}
	}

	int count1 = 0, count2 = 0;

	for (int i = 0; i < a; i++) {
		for (int j = 0 ; j < a; j++) {
			if (vec[i][j] == 1) count1++;
			if (vec[j][i] == 1) count2++;
		}
		if (count1 == 0) que1.push(i);
		if (count2 == 0) que2.push(i);
		count1 = 0; count2 = 0;
	}

	std::cout << que2.size() << " ";
	while(que2.size() > 0) {
		std::cout << que2.front() + 1 << " ";
		que2.pop();
	}
	std::cout << std::endl;

	std::cout << que1.size() << " ";
	while(que1.size() > 0) {
		std::cout << que1.front() + 1 << " ";
		que1.pop();
	}

	return 0;
}
