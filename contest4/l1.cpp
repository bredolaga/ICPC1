#include <iostream>
#include <vector>

int main () {
	int a; std::cin >> a;
	if (a == 0) {
		std::cout << 0;
		return 0;
	}
	std::vector <int> vec(30);
	vec[0] = 2; vec[1] = 4;
	int q = 2;
	while (q < a){
		vec[q] = vec[q - 1] + vec[q - 2];
		q++;
	}
	std::cout << vec[a - 1];
	return 0;
}

	
