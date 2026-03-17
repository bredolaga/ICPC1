#include <string>
#include <iostream>

int n;

void gen (std::string str, int placed, int placedl) {
	if (str.size() == n * 2 - 1) {
		std::cout << str << ")" << std::endl;
		return;
	}
	
	if (placed < n){
		placed += 1;
		gen(str + "(", placed, placedl);
		placed -= 1;
	}
	if (placed >= placedl) {
		placedl += 1;
		gen(str + ")", placed, placedl);
		placedl -= 1;
	}
}

int main () {
	std::cin >> n;
	int placed = 1, placedl = 1;
	gen("(", placed, placedl);
	return 0;
}
