#include <iostream>
#include <vector>
#include <algorithm>
const long long INF = 4e18;
int n;
std::vector <std::vector<std::pair<int, int>>> edges;
std::vector <long long> path;
std::vector <bool> was;
std::vector <int> parent;

int main () {
	int m;
	std::cin >> n >> m;
	int start, end;
	std::cin >> start >> end;
	edges.resize(n + 1);
	path.resize(n + 1, INF);
	was.resize(n + 1, false);
	parent.resize(n + 1);
	path[start] = 0;
	parent[start] = 0;
	while (m--) {
		int x, y, z;
		std::cin >> x >> y >> z;
		edges[x].push_back({y, z});
		edges[y].push_back({x, z});
	}
	
	for (int i = 1; i <= n; i++) {
		int v = -1;
		
		for (int j = 1;j <= n; j++) {
			if (!was[j] && (v == -1 || path[v] > path[j])) v = j;
		}
		if (v == -1 || path[v] == INF) continue;
		was[v] = true;

		for (auto [to, w] : edges[v]) {
			if (path[to] > path[v] + w) {
				path[to] = path[v] + w;
				parent[to] = v;
			}
		}
	}
	std::cout << path[end] << std::endl;
	std::vector <int> ans;
	bool flag = true;
	int x = end;
	while (flag) {
		ans.push_back(x);
		if (parent[x] == 0) break;
		x = parent[x];
	}
	std::reverse(ans.begin(), ans.end());
		
	for (auto x : ans) std::cout << x << " ";
	return 0;
}


	
