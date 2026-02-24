#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int a, b, c;
};

int main () {
	int T; std::cin >> T;
	while (T-- > 0) {
		int q, w, count = 0;
		std::cin >> q >> w;
		std::vector <int> vec(q);
		std::vector <int> vec2(q);
		std::vector <Node> vec3;
		for (int i = 0;i < q;i++) std::cin >> vec[i];
		for (int i = 0;i < q;i++) {
			std::cin >> vec2[i];
			vec3.push_back({vec[i] - vec2[i], vec[i], vec2[i]});
		}
		sort(vec3.begin(), vec3.end(), [](const Node &x, const Node &y) {
  		return x.a < y.a;
		});
		
		int a = 0;
		while (w >= 0) {
			if (w >= vec3[a].b) {
				w -= vec3[a].b;
				if (w < 0) break;
				w += vec3[a].c;
				count ++;
			}	
			else a++;
			if (a == q) break;
		}
		std::cout << count << std::endl;
	}
	return 0;
}
		

