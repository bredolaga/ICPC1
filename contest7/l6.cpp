#include <iostream>
#include <vector>

std::vector <int> vec, tree(100000 * 4 + 5), smax(100000 * 4 + 5);

void pull(int num) {
    int l = num * 2;
    int r = num * 2 + 1;
    tree[num] = std::max(tree[l], tree[r]);
    if (tree[l] > tree[r]) {
        smax[num] = std::max(smax[l], tree[r]);
    } else {
        smax[num] = std::max(tree[l], smax[r]);
    }
}

void gen(int l, int r, int num) {
	if (l == r) {
		tree[num] = vec[l];
		smax[num] = 0;
		return;
	}
	int mid = (l + r) / 2;
	gen(l, mid, num * 2);
	gen(mid + 1, r, num * 2 + 1);
	pull(num);
}

void change (int l, int r, int num, int pos, int x) {
	if (l > pos || r < pos) return;
	if (l == r){
		tree[num] = x;
		smax[num] = 0;
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid) change(l, mid, num * 2, pos, x);
	else change(mid + 1, r, num * 2 + 1, pos, x);
	pull(num);
}

struct Node {
    int mx;
    int smx;
};

Node merge(Node a, Node b) {
    Node res;
    if (a.mx > b.mx) {
        res.mx = a.mx;
        res.smx = std::max(a.smx, b.mx);
    } else {
        res.mx = b.mx;
        res.smx = std::max(a.mx, b.smx);
    }
    return res;
}

Node show(int l, int r, int num, int left, int right) {
    if (l > right || r < left) return {0, 0};

    if (left <= l && r <= right) {
        return {tree[num], smax[num]};
    }

    int mid = (l + r) / 2;
    Node q1 = show(l, mid, num * 2, left, right);
    Node q2 = show(mid + 1, r, num * 2 + 1, left, right);

    return merge(q1, q2);
}

int main() {
	int a; std::cin >> a;
	for (int i = 0; i < a; i++) {
		int q; std::cin >> q;
		vec.push_back(q);
	}
	int b; std::cin >> b;
	gen(0, a - 1, 1);
	while(b--) {
		char y; std::cin >> y;
		int z, x; std::cin >> z >> x;
		z--;
		if (y == 'U') change(0, a - 1, 1, z, x);
		else {
			x--;
			Node ans = show(0, a - 1, 1, z, x);
			std::cout << ans.mx + ans.smx << '\n';
		}
	}
	return 0;
}
	
