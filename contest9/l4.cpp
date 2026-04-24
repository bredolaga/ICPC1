#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::pair<int, int>>> edges;
std::vector<int> in, up;
std::vector<bool> vertex, point;
int num = 1;

void dfs(int x, int parent_edge) {
	vertex[x] = true;
	in[x] = num;
	up[x] = num;
	num++;

	int children = 0;

	for (int i = 0; i < edges[x].size(); i++) {
		int to = edges[x][i].first;
		int id = edges[x][i].second;

		if (id == parent_edge) continue;

		if (!vertex[to]) {
			children++;
			dfs(to, id);
			up[x] = std::min(up[x], up[to]);

			if (parent_edge != -1 && up[to] >= in[x]) {
				point[x] = true;
			}
		}
		else {
			up[x] = std::min(up[x], in[to]);
		}
	}

	if (parent_edge == -1 && children > 1) {
		point[x] = true;
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;

	edges.resize(n + 1);
	in.resize(n + 1);
	up.resize(n + 1);
	vertex.resize(n + 1, false);
	point.resize(n + 1, false);

	for (int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		edges[x].push_back({y, i});
		edges[y].push_back({x, i});
	}

	for (int i = 1; i <= n; i++) {
		if (!vertex[i]) dfs(i, -1);
	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (point[i]) count++;
	}

	std::cout << count << '\n';
	for (int i = 1; i <= n; i++) {
		if (point[i]) std::cout << i << '\n';
	}

	return 0;
}
