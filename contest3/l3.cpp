#include <iostream>
#include <string>

int main () {
	int count = 0, q = 0;
	char lr, nt; int qwe;
	std::string a, b;
	std::cin >> qwe >> a >> b;
	while (q < qwe) {
		if (a[q] == b[q]) {
			q++; continue;
		}
		else if (a[q] != b[q]) {
			lr = a[q]; nt = b[q]; count++;
			while (q < (int)a.size() && a[q] != b[q] && ((a[q] == lr && b[q] == nt) || (a[q] == nt && b[q] == lr))) q++;
		}
	}
	std::cout << count;
	return 0;
}
