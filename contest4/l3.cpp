#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

int main () {
	int a; std::cin >> a;
	std::vector <int> nails(a);
	std::vector <int> gp(a);
	for (int i = 0; i < a;i++) std::cin >> nails[i];
	std::sort(nails.begin(), nails.end());
	gp[0] = 0;
	gp[1] = nails[1] - nails[0];
	gp[2] = nails[2] - nails[0];
	for (int i = 3; i < a;i++) {
		gp[i] = std::min((gp[i - 1] + (nails[i] - nails[i - 1])), (gp[i - 2] + nails[i] - nails [i - 1]));
	}
	std::cout << gp[a - 1];
	return 0;
}
