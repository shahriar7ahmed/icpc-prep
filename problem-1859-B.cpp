#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> mins(n), secs(n);
        for (int i = 0; i < n; ++i) {
            int m; cin >> m;
            ll min1 = LLONG_MAX, min2 = LLONG_MAX;
            for (int j = 0; j < m; ++j) {
                ll x; cin >> x;
                if (x < min1) {
                    min2 = min1;
                    min1 = x;
                } else if (x < min2) {
                    min2 = x;
                }
            }
            mins[i] = min1;
            secs[i] = min2;
        }

        ll sumSecs = 0;
        ll mnMin = LLONG_MAX, mnSec = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            sumSecs += secs[i];
            mnMin = min(mnMin, mins[i]);
            mnSec = min(mnSec, secs[i]);
        }

        ll ans = sumSecs - mnSec + mnMin;
        cout << ans << '\n';
    }

    return 0;
}
