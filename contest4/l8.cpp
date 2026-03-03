#include <iostream>
#include <vector>
#include <algorithm>

int main () {
	int a; std::cin >> a;
	std::vector <int> sub(a + 1);
	for (int i = 1; i <= a; i++) std::cin >> sub[i];
	int b; std::cin >> b;
	std::vector <int> str(b + 1);
	for (int i = 1; i <= b; i++) std::cin >> str[i];
	std::vector<int> prev(b + 1, 0), cur(b + 1, 0);
	for (int i = 1; i <= a;i++) {
		cur[0] = 0;
		for (int q = 1; q <= b; q++) {
				if (sub[i] == str[q]) cur[q] = prev[q - 1] + 1;
				else cur[q] = std::max(prev[q], cur[q - 1]);
			}
		std::swap(prev, cur);
		}
	std::cout << prev[b];
	return 0;
}
