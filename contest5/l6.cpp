#include <iostream>
#include <vector>

long long gcd(long long a, long long b) {
	int c = 1;
	while (c != 0) {
		c = a % b;
		a = b; b = c;
	}
	return a;
}


long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

int main () {
	int a; std::cin >> a;
	std::vector <int> vec(a);
	std::vector <bool> perm(a, false);

	for (int i = 0;i < a;i++) std::cin >> vec[i];
	long long answer = 1;
	for (int i = 0;i < a;i++) {
		if (perm[i]) continue;
		else {
			int num = i, count = 0;
			while (!perm[num]){
				perm[num] = true;
				num = vec[num] - 1;
				count++;
			}
			answer = lcm(answer, count);
		}
	}
	std::cout << answer;
	return 0;
}
				
