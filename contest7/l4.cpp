#include <iostream>
#include <vector>

std::vector <long long> vec(1000000 * 4 + 5, 0);

void change (int l, int r, int num, int left, int right, int x) {
	if (l > right || r < left) return;
	if (l == r) {
		vec[num] += x;
		return;
	}
	int mid = (l + r) / 2;
	change(l, mid, num * 2, left, right, x);
	change(mid + 1, r, num * 2 + 1, left, right, x);
}

void show (int l, int r, int num, int found) {
	if (l > found || r < found) return;
	if (l == r) {
		std::cout << vec[num] << std::endl;
		return;
	}
	int mid = (l + r) / 2;
	show(l , mid, num * 2, found);
	show(mid + 1, r, num * 2 + 1, found);
}

int main () {
	int a, b;
	std::cin >> a >> b;
	while (b > 0) {
		char letter;
		std::cin >> letter;
		if (letter == 'A') {
			int l, r, x;
			std::cin >> l >> r >> x;
			change(1, a - 1, 1, l, r, x);
		}
		else {
			int x;
			std::cin >> x;
			show(1, a - 1, 1, x);
		}
	b--;
	}
	return 0;
}
