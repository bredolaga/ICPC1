#include <iostream>
#include <vector>
#include <algorithm>

std::vector <int> up, in;
std::vector <std::vector<int>> edges;
std::vector <bool> ver;
int k;

int num = 1;
int dfs (int x, int parrent) {
	ver[x] = true;
	int cur = num; num ++;
	in[x] = cur;
	up[x] = cur;

	for (int i = 0; i < edges[x].size(); i ++) {
		if(edges[x][i] == parrent) continue;
		if (!ver[edges[x][i]]) {
			up[x] = std::min(dfs(edges[x][i], x), up[x]);
		}
		else {
			up[x] = std::min(up[x], in[edges[x][i]]);
		}
	}
	return up[x];
}
	

int main () {
	int n, m;
	std::cin >> n >> m;
	up.resize(n + 1);
	in.resize(n + 1);
	edges.resize(n + 1);
	ver.resize(n + 1, false);
	while (m--) {
		int x, y;
		std::cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	std::cin >> k;
	for (int i = 1; i<=n; i++) {
		std::sort(edges[i].begin(), edges[i].end());
	}

	dfs(k, -1);
	
	for (int i = 1; i <= n; i++) {
		std::cout << in[i] << " " << up[i] << '\n';
	}
	return 0;
}
