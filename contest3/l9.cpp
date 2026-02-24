#include <iostream>
#include <vector>
#include <map>
#include <set>

int main () {
	int a, mx = 0; std::cin >> a;
	std::vector <std::pair<int, int>> vec;
	std::map <int, int> mp;
	std
	for (int i = 0;i < a; i++) {
		int q, w;
		std::cin >> q >> w;
		vec.push_back({q, w});
		mp[q] += w;
		if (mx < w)mx = w;
		s
	}
	int sum = 0; int q = vec[a - 1].first;
	int damage = 0; bool found = false;
	for (int i = 0;i < mx;i++) {
		int sum = i;
		for (auto x : mp) {
			if (sum >= x.first) sum += x.second;
			if (sum - i >= q) {
				found = true;
				damage = i;
				break;
			}
		}
		if (found) break;
	}
	for (int i = 0; i < a;i ++) {
		if (vec[i].second >= damage) {
			std::cout << vec[i].first;
			return 0;
		}
	}
	std::cout << "gg";
	return 0;
}
