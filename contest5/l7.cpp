#include <iostream>
#include <vector>

int main () {
	int a; std::cin >> a;
	std::vector <int> perm(a);
	std::vector <bool> used(a, false);
	std::vector <long long> fc(13);
	fc[0] = 1, fc[1] = 1;
	for (int i = 2; i < 13;i ++) {
		fc[i] =  fc[i - 1] * i;
	}
	long long count = 0;
	for (int i = 0; i < a; i++) std::cin >> perm[i];
	for (int i = 0; i < a; i++) {
		int ct = 0;
		for (int q = 1; q < perm[i]; q++) {
			if (!used[q] && perm[i] > q) ct ++;
		}
		count += fc[a - i - 1] * ct;
		used[perm[i]] = true;
		}
	std::cout << count + 1;
	return 0;
}	
