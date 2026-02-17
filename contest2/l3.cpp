#include <iostream>
#include <vector>

int main () {
	int q; std::cin >> q;
	while (q-- > 0) {
		std::vector <int> vec;
	int a, sum = 0; std::cin >> a;
	for (int i = 0; i < a / 2; i ++) {
		sum += i;
		vec.push_back(sum);
	}
	int l = 0, r = 0;
	bool flag = false;
	while (l < vec.size() - 1){
		if (l == vec.size() || r == vec.size()) break;
		int qwe = vec[r] - vec[l];
		if (qwe == a) {
			flag = true;
			break;
		}
		else if (qwe < a)
			r++;
		else l++;
	}
	if (!flag) std::cout << "IMPOSSIBLE" << std::endl;
	else {
		std::cout <<  a << " = ";
		for (int i = l + 1; i < r; i++){
			std::cout << i << " + ";
		}
		std::cout << r << std::endl;
	}
	}
	return 0;
}

