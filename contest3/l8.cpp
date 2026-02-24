#include <vector>
#include <algorithm>
#include <iostream>

int main () {
	int a, b, c = 0;
	std::cin >> a >> b;
	std::vector<int> vec(a);
	for (int i = 0;i < a;i ++) std::cin >> vec[i];
	std::sort(vec.begin(), vec.end(), std::greater<>());
	std::vector<int> answer(b);
	for (int i = 0; i < a;i ++) {
		if (c < b) {
			answer[c] = vec[i];
			c++;
		}
		else {
			int minn = 9999999, qwe = 0;
			for (int w = 0; w < b;w++) {
				if (answer[w] < minn){
					minn = answer[w];
					qwe = w;
				}
			}	
			answer[qwe] += vec[i];
		}
	}	
	int rew = 9999999;
	for (int i = 0; i < b;i++) {
		if (answer[i] < rew) rew = answer[i];
	}
	std::cout << rew;
	return 0;
}


