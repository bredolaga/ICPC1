#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main () {
	int x, y, a, b;
	std::cin >> x >> y >> a >> b;
	long long limit = std::max(x, y) + a + b + 200;
	std::vector <int> ver(limit, -1);
	std::vector <int> cost(limit);

	std::queue <int> que;
	que.push(x);
	ver[x] = 1;
	cost[x] = 0;

	while (!que.empty()) {
		int w = que.front();
		que.pop();
		
		if ((w + a) >= 0 && (w + a) < limit){
			int u1 = w + a;
			if (ver[u1] == -1) {
				cost[u1] = cost[w] + 1;
				ver[u1] = 1;
				que.push(u1);
			}
		}
		if ((w - b) >= 0 && (w - b) < limit) {
			int u2 = w - b;
			if (ver[u2] == -1) {
				cost[u2] = cost[w] + 1;
				ver[u2] = 1;
				que.push(u2);
			}
		}
	}
	
	if (ver[y] == -1) std::cout << -1;
	else std::cout << cost[y];
	return 0;
}


