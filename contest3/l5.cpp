#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    long long a, b;
    int e;
};

auto cmp = [](const Item& x, const Item& y) {
    __int128 left  = (__int128)x.a * y.b;
    __int128 right = (__int128)y.a * x.b;
    if (left != right) return left < right;  
    return x.e < y.e;                        
};

int main () {
	int T;
	while (std::cin >> T){
	long long a, b;
	std::vector <Item> vec;
	int e = 1;
		while (T-- > 0) {
		std::cin >> a >> b;
		vec.push_back({a , b, e});
		e++;
	}
	std::sort(vec.begin(), vec.end(), cmp);	
	bool flag = false;
	for (auto x : vec) {
		if (!flag) flag = true;
		else std::cout << " ";
		std::cout << x.e;
		}
	std::cout << "\n";
	}

	return 0;
}
