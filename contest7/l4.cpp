#include <iostream>
#include <vector>

std::vector <long long> vec(1000000 * 4 + 5, 0);

void change (int l, int r, int num, int left, int right, int x) {
	if (l > right || r < left) return;
	if (l >= left && right >= r) {
		vec[num] += x;
		return;
	}
	int mid = (l + r) / 2;
	change(l, mid, num * 2, left, right, x);
	change(mid + 1, r, num * 2 + 1, left, right, x);
}

void show (int l, int r, int num, int found, long long count) {
	if (l > found || r < found) return;
	count += vec[num];
	if (l == r) {
		std::cout << count << '\n';
		return;
	}
	int mid = (l + r) / 2;
	if (mid >= found) show(l , mid, num * 2, found, count);
	else show(mid + 1, r, num * 2 + 1, found, count);
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int a, b;
	std::cin >> a >> b;
	while (b > 0) {
		char letter;
		std::cin >> letter;
		if (letter == 'A') {
			int l, r, x;
			std::cin >> l >> r >> x;
			change(0, a - 1, 1, l, r, x);
		}
		else {
			int x;
			std::cin >> x;
			show(0, a - 1, 1, x, 0);
		}
	b--;
	}
	return 0;
}
