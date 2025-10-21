#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<bool> seen(n + 1, false);
    int target = n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        seen[x] = true;
        if (seen[target]) {
            bool first = true;
            while (target > 0 && seen[target]) {
                if (!first) cout << ' ';
                cout << target;
                first = false;
                --target;
            }
            cout << '\n';
        } else {
            cout << '\n';
        }
    }
    return 0;
}