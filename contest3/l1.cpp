#include <iostream>
#include <vector>
#include <algorithm>

int main () {
	int a; std::cin >> a;
	std::vector <std::pair<int, int>> vec;
	for (int i = 0;i < a;i++) {
		int q, w;
		std::cin >> q >> w;
		vec.push_back({q, w});
	}
		std::sort(vec.begin(), vec.end(),
    			[](const auto& a, const auto& b) {
        			return a.second < b.second;
    			});

		int count = 0;
    		int last_r = -1e9;

    		for (auto [l, r] : vec) {
        		if (l >= last_r) {   
            		count++;
            		last_r = r;
        		}
    		}
	std::cout << count;
	return 0;
}

