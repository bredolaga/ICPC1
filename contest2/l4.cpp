#include <iostream>

int main() {
	int a; std::cin >> a;
	int count = 0; 
	for (int i = 1;i <= a;i ++) {
		count += a / i;
	}
	std::cout << count;
	return 0;
}

