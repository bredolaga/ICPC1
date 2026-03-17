#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> perm;
vector<bool> used;

void gen() {
    if (perm.size() == n) {
        for (int x : perm) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            perm.push_back(i);

            gen();

            perm.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    used.resize(n + 1, false);
    gen();
}
