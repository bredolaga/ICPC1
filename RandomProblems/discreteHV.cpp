#include <bits/stdc++.h>
using namespace std;

static string term_for_row(const string& bits, const vector<string>& vars) {
    string t = "(";
    for (int i = 0; i < (int)vars.size(); ++i) {
        if (i) t += " & ";
        if (bits[i] == '0') t += "!";
        t += vars[i];
    }
    t += ")";
    return t;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<string> vars(n);
    for (int i = 0; i < n; ++i) cin >> vars[i];
    int m;
    cin >> m;
    vector<string> ones;
    ones.reserve(m);
    for (int i = 0; i < m; ++i) {
        string bits;
        int val;
        cin >> bits >> val;
        if ((int)bits.size() != n) {
            cerr << "Error: bits length != n\n";
            return 1;
        }
        for (char c : bits) {
            if (c != '0' && c != '1') {
                cerr << "Error: bits must be 0/1\n";
                return 1;
            }
        }
        if (val != 0 && val != 1) {
            cerr << "Error: value must be 0/1\n";
            return 1;
        }
        if (val == 1) ones.push_back(term_for_row(bits, vars));
    }

    if (ones.empty()) {
        cout << "0\n";       
        return 0;
    }
    if ((int)ones.size() == m) {
        cout << "1\n";      
        return 0;
    }
    for (int i = 0; i < (int)ones.size(); ++i) {
        if (i) cout << " | ";
        cout << ones[i];
    }
    cout << "\n";
    return 0;
}

/*
3
a b c
8
000 0
001 1
010 0
011 1
100 0
101 0
110 1
111 1
*/
