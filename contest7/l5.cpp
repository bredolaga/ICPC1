#include <iostream>
#include <vector>

std::vector <long long> vec(100000 * 4 + 5, 0);

void find(int l, int r, int num, int left, int right) {
	if (l > right || r < left) return;
	if (l == r);
	int mid = (l + r) / 2;
	find(l, mid, num * 2, left, right);
	find(mid + 1, r, num * 2 + 1, left, right);

int main () {
	int a, b;
	std::cin >> a >> b;
	while (b > 0) {
		int l, r;
		std::cin >> l >> r;
		find(0, a, 1, l, r);
	}
	int m; std::cin >> m;
	return 0;
}
