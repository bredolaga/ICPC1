#include <iostream> 
#include <vector>

int main () {
	int a; std::cin >> a;
	std::vector <int> vec(a + 1, 0);
	for (int i = 1; i < a + 1 ; i++) {
		int x; std::cin >> x;
		vec[i] = vec[i - 1] + x;
	}
	int q; std::cin >> q;
	while (q-- > 0) {
		int l, r;
		std::cin >> l >> r;
		std::cout << vec[r] - vec[l - 1] << std::endl;
	}
return 0;
}

