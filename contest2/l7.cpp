#include <iostream>
#include <string>

int main() {
	int a, w = 0; std::cin >> a;
	bool flag = true;
	std::string s;
	while (a > 0) {
		s = char('0' + a % 2) + s; w++;
		a /= 2;
	}
	for (int i = 0; i < w;i++){
		if (s[i] == '0') std::cout << "S";
		else {
			if (flag) flag = false;
			else std::cout << "SX";
		}
	}
	return 0;
}

