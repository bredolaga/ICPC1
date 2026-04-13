#include <iostream>
#include <queue>

int main () {
	int a; std::cin >> a;
	std::queue <int> que;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			int x; std::cin >> x;
			if (x != 0) que.push(j + 1);
		}
		std::cout << que.size() << " ";
		while (que.size() > 0) {
			std::cout << que.front() << " ";
			que.pop();
		}
		std::cout << std::endl;
	}
	return 0;
}


