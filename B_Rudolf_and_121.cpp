#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        bool ok = true;
        for (int i = 0; i <= n - 3 && ok; ++i) {
            long long x = a[i];
            if (a[i + 1] < 2 * x || a[i + 2] < x) ok = false;
            else {
                a[i + 1] -= 2 * x;
                a[i + 2] -= x;
                a[i] = 0;
            }
        }
        if (ok && a[n - 2] == 0 && a[n - 1] == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}