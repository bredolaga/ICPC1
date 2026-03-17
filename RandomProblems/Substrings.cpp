#include <iostream>
#include <vector>

std::vector <int> perm;
int n;

void gen (int i) {
	if (i > n) {
		for (auto x : perm) std::cout << x << " ";
		std::cout << std::endl;
		return;
	}

	gen(i + 1);

	perm.push_back(i);
	gen(i + 1);
	perm.pop_back();
}

int main () {
	std::cin >> n;
	gen(1);
	return 0;
}


