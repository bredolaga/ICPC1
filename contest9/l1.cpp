#include <iostream>
#include <vector>

std::vector <int> enter, out;
std::vector <std::vector<int>> edges;
std::vector <bool> ver;
int num = 1;

void dfs(int x) {
	enter[x] = num;
	num++; ver[x] = true;
	for (int i = 0;i < edges[x].size(); i++) {
		if (!ver[edges[x][i]]) {
			dfs(edges[x][i]);
		}
	}
	out[x] = num;
	num++;
	return;
}
	

int main () {
	int a, b;
	std::cin >> a >> b;
	ver.resize(a + 1, false);
	edges.resize(a + 1);
	enter.resize(a + 1);
	out.resize(a + 1);

	while (b--) {
		int x, y;
		std::cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int x; 
	std::cin >> x;

	dfs(x);

	for (int i = 1; i <= a;i ++) {
		std::cout << enter[i] << " " << out[i] << '\n';
	}


	return 0;
}


