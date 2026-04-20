#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::pair<int, int>>> edges;
std::vector<int> up, in;
std::vector<bool> used;
std::vector<int> bridges;
int timer = 1;

void dfs(int v, int parent_edge) {
    used[v] = true;
    in[v] = up[v] = timer++;
    
    for (auto e : edges[v]) {
        int to = e.first;
        int id = e.second;
        
        if (id == parent_edge) continue;
        
        if (!used[to]) {
            dfs(to, id);
            up[v] = std::min(up[v], up[to]);
            
            if (up[to] > in[v]) {
                bridges.push_back(id);
            }
        } else {
            up[v] = std::min(up[v], in[to]);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    edges.resize(n + 1);
    up.resize(n + 1);
    in.resize(n + 1);
    used.resize(n + 1, false);
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        edges[x].push_back({y, i});
        edges[y].push_back({x, i});
    }
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) dfs(i, -1);
    }
    
    std::sort(bridges.begin(), bridges.end());
    
    std::cout << bridges.size() << '\n';
    for (int x : bridges) {
        std::cout << x << ' ';
    }
    
    return 0;
}
