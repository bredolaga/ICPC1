#include <iostream>
#include <vector>
#include <algorithm>

int main () {
	int t ;std::cin >> t;
	long long max = 1000000000000, lim = 1000000;
	std::vector <char> vec(lim + 1, true);
	vec[0] = false; vec[1] = false;
		for (long long i = 2;i * i * 1LL <= lim;i++) {
			if (vec[i]) {
				for (long long q = i * i * 1LL;q <= lim;q += i) {
					vec[q] = false;
				}
			}
		}

	std::vector <long long> power;
	for (int i = 2;i <= lim;i++) {
		if (vec[i]) {
			long long w = 1ll * i * i;
			while (w <= max) {
				power.push_back(w);
				if (w > max / i) break;
				w *= i;
			}
		}
	}

	std::sort(power.begin(), power.end());
	power.erase(std::unique(power.begin(), power.end()), power.end());

	while (t-- > 0) {
		long long l, r;
		std::cin >> l >> r;
		
        auto it1 = std::lower_bound(power.begin(), power.end(), l);
        auto it2 = std::upper_bound(power.begin(), power.end(), r);
	std::cout << (it2 - it1) << "\n";
    }
	return 0;
}
