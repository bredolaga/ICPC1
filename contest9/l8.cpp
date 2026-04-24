#include <iostream>
#include <vector>
#include <algorithm>

std::vector <std::vector<int>> edges;
std::vector <int> vertex;
std::vector <int> answer;
int n;

bool dfs(int x) {
	vertex[x] = 1;
	for (int i = 0;i < edges[x].size(); i++) {
		int to = edges[x][i];
		if (vertex[to] == 1) return false;
		if (vertex[to] == 2) continue;
		if (vertex[to] == 0) {
			if(!dfs(to)) return false;
		}
	}
	answer.push_back(x);
	vertex[x] = 2;
	return true;
}


int main () { 
	int m;
	std::cin >> n >> m;
	edges.resize(n + 1);
	vertex.resize(n + 1, 0);
	while(m--) {
		int x, y;
		std::cin >> x >> y;
		edges[x].push_back(y);
	}
	for (int i = 1;i <= n;i++) {
		if (vertex[i] == 0) {
			if (!dfs(i)) {
				std::cout << -1;
				return 0;
			}
		}
	}

	std::reverse(answer.begin(), answer.end());
	for (int i = 0;i < answer.size(); i++) {
		std::cout << answer[i] << " ";
	}
	return 0;
}
	


	

