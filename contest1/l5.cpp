#include <iostream>
#include <cmath>

int main () {
	int a; std::cin >> a;
	bool flag = true;
	int q = sqrt(a);
	for (int i = 2;i <= q;i++) {
		if (a % i == 0 ) {
			flag = false;
			break;
		}
	}
	if (flag) std::cout << "Yes";
	else std::cout << "No";
	return 0;
}
