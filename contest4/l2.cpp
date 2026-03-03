#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main () {
	int a; std::cin >> a;
	std::vector <std::pair<long long, int>> move(a);
	std::vector <int> vec(a);
	std::vector <int> parent(a);
	for (int i = 0;i < a; i ++) std::cin >> vec[i];
	move[0].first = 0; move[0].second = 1;
	parent[0] = -1;
	move[1].first = std::abs(vec[1] - vec[0]); move[1].second = 2;
	parent[1] = 0;
	for (int i = 2; i < a;i++) {
		long long x = move[i - 2].first + std::abs((vec[i] - vec[i - 2]) * 3);
		long long y = move[i - 1].first + std::abs(vec[i] - vec[i - 1]);
		if(x == y) {
			move[i].first = x;
			move[i].second = std::min((move[i - 2].second + 1), (move[i - 1].second + 1));
			long long len2 = move[i-2].second + 1;
			long long len1 = move[i-1].second + 1;
			if (len2 <= len1) {
    				move[i].second = len2;
				parent[i] = i - 2;
			}
			else {
				move[i].second = len1;
    				parent[i] = i - 1;
			} 
		}
		else if (x < y) {
			move[i].first = x;
			move[i].second = move[i - 2].second + 1;
			parent[i] = i - 2;
		}
		else {
			move[i].first = y;
			move[i].second = move[i - 1].second + 1;
			parent[i] = i - 1; 
		}
	}
	std::cout << move[a - 1].first << std::endl;
	std::cout << move[a - 1].second << std::endl;
	std::vector<int> path;
	for (int v = a - 1; v != -1; v = parent[v])
    	path.push_back(v);
	std::reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); i++) std::cout << path[i] + 1 << " ";
	return 0;
}

