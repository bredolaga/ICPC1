#include <iostream>
#include <vector>

int main () {
	int a, b;
	std::cin >> a >> b;
	std::vector <int> vec(a);
	for (int i = 0;i < a;i++) std::cin >> vec[i];
	long long l = 0, r = vec[a - 1] - vec[0], ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		int count = 1, run = 0, last = vec[0];
		for (int i = 1; i < a; i++) {
			run = vec[i] - last;
			if (run >= mid) {
				count ++;
				last = vec[i];
			}
		}
		if (count >= b){
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	std::cout << ans;
	return 0;
}
