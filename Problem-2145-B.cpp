#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int zeros = 0, ones = 0, twos = 0;
        for (char c : s) {
            if (c == '0') ++zeros;
            else if (c == '1') ++ones;
            else ++twos;
        }

        int L = zeros;
        int R = zeros + twos;
        int Bmax = ones + twos;

        string ans(n, '?');
        for (int i = 1; i <= n; ++i) {
            int lower = max(L, k - (n - i));
            int upper = min(R, i - 1);
            bool can_survive = (lower <= upper);
            if (!can_survive) {
                ans[i - 1] = '-';
            } else {
                bool always_survive = (i > R) && (i <= n - Bmax);
                ans[i - 1] = always_survive ? '+' : '?';
            }
        }

        cout << ans << '\n';
    }

    return 0;
}