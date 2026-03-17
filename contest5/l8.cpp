#include <iostream>
#include <vector>

int n, sum = 0;
std::vector <int> sq;

void gen (int sum) {
	if (sum == n) {
		for (auto x : sq) std::cout << x << " ";
		std::cout << std::endl;
		return;
	}
	for (int i = 1;i <= n;i ++) {
		if (sq.size() != 0) {
			if (sq[sq.size() - 1] < i || sum + i > n) continue;
			sq.push_back(i);
			sum += i;
			gen(sum);
			sum -= i;
			sq.pop_back();
		}
		else{
			sq.push_back(i);
			sum += i;
			gen(sum);
			sum -= i;
			sq.pop_back();
		}
	}
}

int main () {
	std::cin >> n;
	gen(0);
	return 0;
}

