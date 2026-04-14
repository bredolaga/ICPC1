#include <vector>
#include <iostream>

std::vector <std::vector<int>> graph;
std::vector <int> color;
int a;
	
bool paint(int x) {
	int p = color[x];
	int w;
	if (p == 1) w = 2;
	else w = 1;
	for (int j = 0; j < graph[x].size(); j++) {
		if (color[graph[x][j]] == p) return false;
		if (color[graph[x][j]] == 0) {
			color[graph[x][j]] = w;
			if (!paint(graph[x][j])) return false;
		else continue;
		}
	}
	return true;
}
		
	

	

int main () {
	int b;
	std::cin >> a >> b;
	graph.resize(a + 1);
	color.resize(a + 1, 0);
	while (b--) {
		int x, y;
		std::cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= a; i++) {
		if (color[i] == 0) {
			color[i] = 1;
			if (!paint(i)) {
				std::cout << "NO";
				return 0;
			}
		}
	}
	std::cout << "YES";
	return 0;

}




