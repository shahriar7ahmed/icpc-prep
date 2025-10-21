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
        vector<long long> b(n - 1);
        for (auto &x : b) cin >> x;
        vector<long long> a(n);
        if (n == 2) {
            a[0] = a[1] = b[0];
        } else {
            a[0] = b[0];
            for (int i = 1; i < n - 1; ++i)
                a[i] = min(b[i - 1], b[i]);
            a[n - 1] = b[n - 2];
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}