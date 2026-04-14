#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    int a, b;
    std::cin >> a >> b;

    std::vector<std::vector<int>> vec(n + 1);
    std::vector<int> dist(n + 1, -1);
    std::vector<int> parent(n + 1, -1);

    while (m--) {
        int x, y;
        std::cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    std::queue<int> q;
    q.push(a);
    dist[a] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : vec[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                parent[to] = v;
                q.push(to);
            }
        }
    }

    if (dist[b] == -1) {
        std::cout << -1;
        return 0;
    }

    std::cout << dist[b] << "\n";

    std::vector<int> path;
    int cur = b;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    std::reverse(path.begin(), path.end());

    for (int v : path) {
        std::cout << v << " ";
    }

    return 0;
}
