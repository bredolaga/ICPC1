#include <iostream>
#include <string>

void check (std::string l, std::string r) {
	int count = 0,q = 0;
	for (int i = 0; i < r.size();i++) {
			if (q >= l.size()) break;
	if (r[i] == l[q]) {
			count ++; q++;
		}
	}
	if (count == l.size()) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
}

int main () {
	std::string l, r;
	while (std::cin >> l >> r) {
		check(l, r);
		}
	return 0;
}


