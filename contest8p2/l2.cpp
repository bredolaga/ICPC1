#include <iostream>
#include <vector>
#include <queue>

std::vector <std::vector<int>> vec;
std::vector <bool> ck;
std::queue <int> que;

void found(int x) {
	que.push(x);
	while (que.size() > 0) {
		ck[que.front()] = true;
			for (int j = 0;j < vec[que.front()].size(); j++) {
				if (ck[vec[que.front()][j]] == false){
					que.push(vec[que.front()][j]);
					ck[vec[que.front()][j]] = true;
				
				}
			}
		que.pop();
	}
}

	

int main () {
	int a, b;
	std::cin >> a >> b;
	ck.resize(a + 1, false);
	vec.resize(a + 1);
	while (b--) {
		int x, y;
		std::cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	found(1);
	for (int i = 1; i <= a; i++) {
		if (ck[i] == false) {
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES";
	return 0;
}
