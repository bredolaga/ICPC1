#include <iostream>
#include <algorithm>
#include <vector>

int main () {
	int n, k;
	std::cin >> n >> k;
	std::vector <int> vec(n);
	for (int i = 0 ; i < n;i++) std::cin >> vec[i];
	std::sort(vec.begin(), vec.end());
	
	int count = 0, r = n - 1, i = 0;
	if (vec[r] > k) {
		std::cout << "Impossible";
		return 0;
	}

	while (i <= r) {
		if (i == r) {
			count ++;
			r --;
		}

		else if (vec[i] + vec[r] <= k) {
			r--; i++;
			count ++;
		}
		else {
			count ++;
			r--;
		}
	}

	std::cout << count;
	return 0;
}


