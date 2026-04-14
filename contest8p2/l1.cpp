#include <iostream>
#include <vector>

std::vector<int> parent;

int find(int n) {
	if (parent[n] == n) return n;
	return find(parent[n]);
}

void add(int a, int b) {
	a = find(parent[a]);
	b = find(parent[b]);
	if (a != b) parent[a] = b;
	return;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	parent.resize(a + 1);
	for(int i = 1;i <= a; i++) parent[i] = i;

	while(b--) {
		int x, y;
		std::cin >> x >> y;

		if (find(x) != find(y)) {
			std::cout << x << " " << y << std::endl;
			add(x, y);
		}
	}
	return 0;
}
