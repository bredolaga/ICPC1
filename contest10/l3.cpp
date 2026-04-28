#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector <std::vector<int>> edges, revedges;
std::vector <bool> was;
std::vector <int> tsort, color, in, out;

void topsort (int x) {
	was[x] = true;
	for (int i = 0; i < edges[x].size(); i++) {
		int to = edges[x][i];
		if (!was[to]) topsort(to);
	}
	tsort.push_back(x);
}

int clr = 1;
void paint (int x) {
	color[x] = clr;
	for (int i = 0; i < revedges[x].size(); i++) {
		int to = revedges[x][i];
		if (color[to] == 0) paint(to);
	}
}

	

int main () {
	int m;
	std::cin >> n >> m;
	edges.resize(n);
	revedges.resize(n);
	was.resize(n, false);
	color.resize(n, 0);
	in.resize(n + 1);
	out.resize(n + 1);
	while (m--) {
		int x, y;
		std::cin >> x >> y;
		edges[x].push_back(y);
		revedges[y].push_back(x);
	}

	for (int i = 0;i < n; i++) {
		if (!was[i]) topsort(i);
	}

	std::reverse(tsort.begin(), tsort.end());

	for (int i = 0; i < n; i++) {
		if (color[tsort[i]] == 0) {
			paint(tsort[i]);
			clr++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (auto x : edges[i]) {
			if (color[i] != color[x]) {
				out[color[i]]++;
				in[color[x]]++;
			}
		}
	}

	int countin = 0, countout = 0;
	for (int i = 1; i < clr; i++) {
		if (in[i] == 0) countin ++;
		if (out[i] == 0) countout ++;
	}
	if (clr == 2) {
		std::cout << 1 << " " << 0;
	}
	else {
		std::cout << countin << " " << std::max(countin, countout);
	}
	return 0;
}

	
