#include <iostream>
#include <vector>
#include <algorithm>

int main () {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> vec(n, std::vector<int>(m));
	for (int i = 0;i < n;i ++) {
		for (int q = 0; q < m;q ++) {
			std::cin >> vec[i][q];
		}
	}
	std::vector <std::vector<int>> way(n, std::vector<int>(m));
	way[0][0] = vec[0][0];
	for (int i = 1;i < n; i ++) way[i][0] = way[i - 1][0] + vec[i][0];
	for (int i = 1;i < m; i ++) way[0][i] = way[0][i - 1] + vec[0][i];
	for (int i = 1;i < n; i ++) {
		for (int q = 1;q < m; q++) {
			way[i][q] = std::min(way[i - 1][q] + vec[i][q], way[i][q - 1] + vec[i][q]);
		}
	}
	std::cout << way[n - 1][m - 1] << std::endl;
	std::vector <std::pair<int, int>> path(n + m);
	int x = n - 1, y = m - 1, k = 0;
	while(true) {
		path[k].first = x + 1;
		path[k].second = y + 1;
		k++;
		if (x == 0 && y == 0) break;
		if (x == 0) y--;
		else if (y == 0) x--;
		else {
			if (way[x - 1][y] <= way[x][y - 1]) x--;
			else y --;
		}
	}
	for (int i = k - 1;i >= 0; i--) std::cout << path[i].first << " " << path[i].second << std::endl;
	return 0;
}






