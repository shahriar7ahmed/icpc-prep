#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> sets(n);
        vector<int> cnt(m + 1, 0);
        for (int i = 0; i < n; ++i) {
            int len;
            cin >> len;
            sets[i].resize(len);
            for (int j = 0; j < len; ++j) {
                cin >> sets[i][j];
                ++cnt[sets[i][j]];
            }
        }
        bool ok = true;
        for (int x = 1; x <= m; ++x) {
            if (cnt[x] == 0) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        int droppable = 0;
        for (const auto& s : sets) {
            bool good = true;
            for (int x : s) {
                if (cnt[x] == 1) {
                    good = false;
                    break;
                }
            }
            if (good) ++droppable;
        }
        cout << (droppable >= 2 ? "YES\n" : "NO\n");
    }
    return 0;
}