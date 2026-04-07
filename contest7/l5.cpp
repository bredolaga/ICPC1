#include <iostream>
#include <vector>
#include <algorithm>

std::vector <int> vec, start, end, lenght, group, tree(100000 * 4 + 5, 0);

void gen(int l, int r, int num) {
	if (l == r) {
		tree[num] = lenght[l];
		return;
	}
	int mid = (l + r) / 2;
	gen(l, mid, num * 2);
	gen(mid + 1, r, num * 2 + 1);
	tree[num] = std::max(tree[num * 2], tree[num * 2 + 1]);
}	

int find(int l, int r, int num, int left, int right) {
	if (l > right || r < left) return 0;
	if (left <= l && right >= r) return tree[num];
	int mid = (l + r) / 2;
	return std::max(
	find(l, mid, num * 2, left, right),
	find(mid + 1, r, num * 2 + 1, left, right)
	);
}

int main () {
	int a, b;
	while (std::cin >> a >> b){
	if (a == 0) return 0;
	vec.clear();
	start.clear();
	end.clear();
	lenght.clear();
	group.clear();
	int count = 0, q = 0;
	start.push_back(0);
	for (int i = 0; i < a; i++) {
		int w; std::cin >> w;
		vec.push_back(w);
		if (i > 0) {
			if (vec[i] != vec[i - 1]) {
				end.push_back(i - 1);
				start.push_back(i);
				lenght.push_back(count);
				count = 0;
				q++;
			}
		}
		group.push_back(q);
		count ++;
	}
	end.push_back(a - 1);
	lenght.push_back(count);
	gen(0, lenght.size() - 1, 1);
	while (b--) {
		int l, r;
		std::cin >> l >> r;
		l--; r--;
		int gl = group[l];
		int gr = group[r];
		if (gl == gr) {
			std::cout << r - l + 1 << '\n';
			continue;
		}
		int left_part = end[gl] - l + 1;
		int right_part = r - start[gr] + 1;
		int mid = 0;
		if (gl + 1 <= gr - 1) {
			mid = find(0, lenght.size() - 1, 1, gl + 1, gr - 1);
		}
		std::cout << std::max(std::max(left_part, right_part), mid) << '\n';
	}
	}
}
