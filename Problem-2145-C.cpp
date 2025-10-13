#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int tot = 0;
        for (char c : s) tot += (c == 'a') ? 1 : -1;
        if (tot == 0) {
            cout << 0 << '\n';
            continue;
        }
        const int SHIFT = n;
        vector<int> latest(2 * n + 5, -1);
        latest[SHIFT] = 0;
        int pref = 0;
        int best = n + 1;
        for (int i = 1; i <= n; ++i) {
            pref += (s[i - 1] == 'a') ? 1 : -1;
            int target = pref - tot;
            if (target >= -n && target <= n) {
                int idx = latest[target + SHIFT];
                if (idx != -1) best = min(best, i - idx);
            }
            latest[pref + SHIFT] = i;
        }
        if (best < n) cout << best << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}