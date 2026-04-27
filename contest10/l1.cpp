#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

int n;
std::vector <std::vector<int>> edges, revedges;
std::vector <int> tsort;
std::vector <bool> was;
std::vector <int> color;

void topsort (int x) {
	was[x] = true;
	for (int i = 0; i < edges[x].size(); i++) {
		int to = edges[x][i];
		if (!was[to]) topsort(to);
	}
	tsort.push_back(x);
	return;
}

int clr = 1, count = 0;
void paint(int x) {
	color[x] = clr;
	for (int i = 0; i < revedges[x].size(); i++) {
		int to = revedges[x][i];
		if (color[to] == 0) paint(to);
		if (color[to] == clr) continue;
	}
	return;
}

int main () {
	int m;
	std::cin >> n >> m;
	edges.resize(n + 1);
	revedges.resize(n + 1);
	was.resize(n + 1, false);
	color.resize(n + 1, 0);
	while (m--) {
		int x, y;
		std::cin >> x >> y;
		edges[x].push_back(y);
		revedges[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!was[i]) topsort(i);
	}
	std::reverse(tsort.begin(), tsort.end());
	
	for (auto x : tsort) {
		if (color[x] == 0) {
			paint(x);
			clr++;
		}
	}
	std::set<std::pair<int, int>> s;

	for (int x = 1; x <= n; x++) {
    		for (int to : edges[x]) {
        		if (color[x] != color[to]) {
            			s.insert({color[x], color[to]});
        			}
    			}
		}
	std::cout << s.size();
	return 0;
}
