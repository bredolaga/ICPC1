#include <iostream>
#include <iomanip> 

int main () {
	double q = 100, w = 0;
	int a;std::cin >> a;
		while (a-- > 0) {
			w += q / 2.0;
        		q /= 4.0; 
		}
	std::cout << std::fixed << std::setprecision(5) << w;
	return 0;
}
