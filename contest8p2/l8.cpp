#include <iostream>
#include <vector>
#include <queue>
#include <string>

struct Cell {
    int x, y;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; i++) {
        std::cin >> grid[i];
    }

    Cell start, finish;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '@') start = {i, j};
            if (grid[i][j] == 'X') finish = {i, j};
        }
    }

    std::vector<std::vector<bool>> used(n, std::vector<bool>(n, false));
    std::vector<std::vector<Cell>> parent(n, std::vector<Cell>(n, {-1, -1}));

    std::queue<Cell> q;
    q.push(start);
    used[start.x][start.y] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (used[nx][ny]) continue;
            if (grid[nx][ny] == 'O') continue;

            used[nx][ny] = true;
            parent[nx][ny] = cur;
            q.push({nx, ny});
        }
    }

    if (!used[finish.x][finish.y]) {
        std::cout << "N\n";
        return 0;
    }

    std::cout << "Y\n";

    Cell cur = finish;
    while (!(cur.x == start.x && cur.y == start.y)) {
        if (grid[cur.x][cur.y] != '@') {
            grid[cur.x][cur.y] = '+';
        }
        cur = parent[cur.x][cur.y];
    }

    for (int i = 0; i < n; i++) {
        std::cout << grid[i] << '\n';
    }

    return 0;
}
