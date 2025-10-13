#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<vector<long long>> prefix(2, vector<long long>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            prefix[0][i] = prefix[0][i - 1] + (a[i] == 0);
            prefix[1][i] = prefix[1][i - 1] + (a[i] == 1);
        }
        vector<int> has_adj(n + 1, 0);
        for (int i = 1; i < n; ++i) {
            has_adj[i] = (a[i] == a[i + 1]);
        }
        vector<int> prefix_has(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix_has[i] = prefix_has[i - 1] + has_adj[i - 1];
        }
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            long long count0 = prefix[0][r] - prefix[0][l - 1];
            long long count1 = prefix[1][r] - prefix[1][l - 1];
            if (count0 % 3 != 0 || count1 % 3 != 0) {
                cout << -1 << '\n';
            } else {
                int len = r - l + 1;
                int has_adj_in_range = prefix_has[r] - prefix_has[l];
                if (has_adj_in_range > 0) {
                    cout << len / 3 << '\n';
                } else {
                    cout << 2 + (len - 2) / 3 << '\n';
                }
            }
        }
    }
    return 0;
}