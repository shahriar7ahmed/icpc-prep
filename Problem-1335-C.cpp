#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> freq(n + 1, 0);
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            ++freq[x];
        }
        int distinct = 0, mx = 0;
        for (int f : freq) {
            if (f) {
                ++distinct;
                mx = max(mx, f);
            }
        }
        int ans = max(min(distinct - 1, mx), min(distinct, mx - 1));
        cout << ans << '\n';
    }
    return 0;
}