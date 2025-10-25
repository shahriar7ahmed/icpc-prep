#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        int i = 0, j = 0, common = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                ++common;
                ++i;
                ++j;
            } else if (a[i] < b[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        int uniqueA = n - common;
        int uniqueB = m - common;
        int ans = (uniqueA <= uniqueB) ? (2 * uniqueA + 1) : (2 * uniqueB + 2);
        cout << ans << '\n';
    }
    return 0;
}