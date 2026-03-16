#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

int main() {
    freopen("success.in", "r", stdin);
    freopen("success.out", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) std::cin >> a[i];

    if (!std::next_permutation(a.begin(), a.end()))
        std::sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (i) std::cout << " ";
        std::cout << a[i];
    }
}
