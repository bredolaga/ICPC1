#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::unordered_map<int, int> firstPos;
    std::unordered_map<int, int> lastPos;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (!firstPos.count(a[i])) {
            firstPos[a[i]] = i;
        }
        lastPos[a[i]] = i;
    }
    std::vector<std::pair<int,int>> vec;
    for (const auto& p : firstPos) {
        int x = p.first;
        vec.push_back({firstPos[x], lastPos[x]});
    }
    std::sort(vec.begin(), vec.end(),
        [](const std::pair<int,int>& s1, const std::pair<int,int>& s2) {
            if (s1.second != s2.second) return s1.second < s2.second;
            return s1.first < s2.first;
        });
    int keep = 0;
    int curR = -1;
    for (const auto& seg : vec) {
        int l = seg.first;
        int r = seg.second;
        if (l > curR) {
            ++keep;
            curR = r;
        }
    }
    std::cout << (vec.size() - keep) << "\n";
    return 0;
}
