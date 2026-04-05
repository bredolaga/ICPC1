#include <iostream>
#include <vector>

std::vector<long long> vec(4 * 100000 + 5, 0);

void gen(int size, int num) {
	if (size == 1){
		vec[num] = 0;
		return;
	}
	int left, right;
	left = size / 2;
	right = size - left;
	gen(left, num * 2);
	gen(right, num * 2 + 1);
	vec[num] = vec[num * 2] + vec[num * 2 + 1];
}

void change (int left, int right, int num, int i, int x) {
	if (left > i || right < i) return;
	else if (left == right) {
		vec[num] = x;
		return;
	}
	int mid = (left + right) / 2;
	change(left, mid,num * 2, i, x);
	change(mid + 1, right, num * 2 + 1,i, x);
	vec[num] = vec[num * 2] + vec[num * 2 + 1];
}

long long show(int left, int right, int num, int l, int r) {
	if (left > r || right < l) return 0;
	if (left >= l && right <= r) return vec[num];
	int mid = (left + right) / 2;
	return show(left, mid,num * 2, l, r)
		+ show(mid + 1, right, num * 2 + 1,l, r);
}

int main () {
	int a, b;
	std::cin >> a >> b;
	gen(a, 1);
	while (b > 0) {
		char letter; int num1, num2;
		std::cin >> letter >> num1 >> num2;
		if (letter == 'A') change(1, a, 1, num1, num2);
		else std::cout << show(1, a, 1, num1, num2) << std::endl;
		b--;
	}
	return 0;
}
