#include <iostream>
#include <vector>
#include <algorithm>

std::vector <long long> vecmax(4 * 100000 + 5, 0);
std::vector <long long> vecmin(4 * 100000 + 5, 0);
int number = 1;

void gen(int l, int r, int num){
	if (l == r) {
		vecmax[num] = ((1LL * number * number) % 12345) 
			+ ((1LL * number * number * number) % 23456);
		vecmin[num] = ((1LL * number * number) % 12345) 
			+ ((1LL * number * number * number) % 23456);
		number ++;
		return;
	}
	int mid = (l + r) / 2;
	gen(l, mid, num * 2);
	gen(mid + 1, r, num * 2 + 1);
	vecmax[num] = std::max(vecmax[num * 2], vecmax[num * 2 + 1]);
	vecmin[num] = std::min(vecmin[num * 2], vecmin[num * 2 + 1]);
}

void change(int l, int r, int num, int x, int y){
	if (l > x || r < x) return;
	if (l == r) {
		vecmax[num] = y;
		vecmin[num] = y;
		return;
	}
	int mid = (l + r) / 2;
	change(l, mid, num * 2, x, y);
	change(mid + 1, r, num * 2 + 1, x, y);
	vecmax[num] = std::max(vecmax[num * 2], vecmax[num * 2 + 1]);
	vecmin[num] = std::min(vecmin[num * 2], vecmin[num * 2 + 1]);
}

long long fmin(int l, int r, int num,int left, int right) {
	if(l > right || r < left) return (long long)1e18;
	if(l >= left && r <= right) return vecmin[num];
	int mid = (l + r) / 2;
	return std::min(fmin(l, mid, num * 2, left, right),
			fmin(mid + 1, r, num * 2 + 1, left, right));
}

long long fmax(int l, int r, int num,int left, int right) {
	if(l > right || r < left) return (long long)-1e18;
	if(l >= left && r <= right) return vecmax[num];
	int mid = (l + r) / 2;
	return std::max(fmax(l, mid, num * 2, left, right),
		fmax(mid + 1, r, num * 2 + 1, left, right));
}

void show(int l, int r,int num, int left, int right) {
	std::cout << fmax(l, r, num, left, right) - fmin(l, r, num, left, right) << std::endl;
}

int main () {
	int a; std::cin >> a;
	gen(1, 100000, 1);
	while(a > 0) {
		int x, y;
		std::cin >> x >> y;
		if (x > 0) show(1, 100000, 1, x, y);
		else change(1, 100000, 1, -x, y);
		a--;
	}
	return 0;
}

		
