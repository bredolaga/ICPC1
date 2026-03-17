#include <iostream>
#include <string>
int n;

void gen(std::string s) {
	if (s.size() == n) {
		bool flag = false;
		for (auto x : s) {
			if (!flag) flag = true;
			else std::cout << " ";
			std::cout << x;
		}
		std::cout << "\n";
        	return;
    }
	gen(s + "0");
	if (s[s.size() - 1] == '0' || s.size() == 0) gen(s + "1");
}

int main() {
	std::cin >> n;
	gen("");
}
