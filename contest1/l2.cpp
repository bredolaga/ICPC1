#include <iostream>

int main () {
	std::string str;
	std::cin >> str;
	int a; std::cin >> a;
	for (int i = 0;i < str.size();i++) {
		for (int q = 0;q < a;q++) {
			if (str[i] == 'A') str[i] = 'Z';
			else str[i]--;
		}
	}
	std::cout << str;
	return 0;
}
