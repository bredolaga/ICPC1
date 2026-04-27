#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int n;
std::vector <std::vector<int>> edges, revedges;
std::vector <bool> was;
std::vector <int> color, out, tsort, station;

void topsort (int x) {
	was[x] = true;
	for (int i = 0; i < edges[x].size(); i++) {
		int to = edges[x][i];
		if (!was[to]) topsort(to);
	}
	tsort.push_back(x);
	return;
}
int clr = 1;
void paint (int x) {
	color[x] = clr;
	for (int i = 0; i < revedges[x].size(); i++) {
		int to = revedges[x][i];
		if (color[to] == 0) paint(to);
	}
}

int main() {
	int m;
	std::cin >> n;
	std::cin >> m;
	edges.resize(n + 1);
	revedges.resize(n + 1);
	was.resize(n + 1, false);
	color.resize(n + 1, 0);
	station.resize(n + 1, 0);
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
			station[clr] = x;
			clr++;
		}
	}

	out.resize(clr + 1, 0);

	for (int v = 0; v <= n; v++) {
        	for (int to : edges[v]) {
            		if (color[v] != color[to]) {
                		out[color[v]]++;
            			}
        		}
    		}

    	std::vector<int> ans;

    	for (int c = 1; c < clr; c++) {
        	if (out[c] == 0) {
            		ans.push_back(station[c]);
        		}
    		}

    	std::cout << ans.size() << '\n';

    	for (int i = ans.size() - 1; i >= 0; i--) {
        	std::cout << ans[i] << " ";
    	}
	return 0;
}
