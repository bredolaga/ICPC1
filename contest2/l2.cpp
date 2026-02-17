#include <iostream>
#include <map>

int main () {
	int a ;std::cin >> a;
	std::map <int, int> mp;
	int b = 2;
	while (a != 1) {
		if (a % b == 0) {
			a /= b; mp[b]++;
			}
		else b ++;
	}
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second == 1) std::cout << it->first;
        else std::cout << it->first << "^" << it->second;
        if (std::next(it) != mp.end()) std::cout << "*";
    }
	return 0;
}
