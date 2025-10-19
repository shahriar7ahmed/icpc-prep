#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_sum += a[i];
        }
        vector<long long> b = a;
        sort(b.begin(), b.end());
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + b[i - 1];
        }
        long long max_sum = total_sum;
        for (int x = 1; x <= n; x += 2) {
            int m = (x + 1) / 2;
            if (m > n) continue;
            long long v = b[n - m];
            // find number < v
            auto it = lower_bound(b.begin(), b.end(), v);
            int idx = it - b.begin();
            int s = idx;
            // number == v
            int eq = 0;
            if (idx < n && b[idx] == v) {
                auto it2 = upper_bound(it, b.end(), v);
                eq = it2 - it;
            }
            if (eq < m) continue;
            int can_upgrade = min(s, k * (x - m));
            if (can_upgrade > 0) {
                // sum of smallest can_upgrade small elements
                long long sum_small = prefix[can_upgrade];
                long long increase = can_upgrade * 1LL * v - sum_small;
                max_sum = max(max_sum, total_sum + increase);
            } else {
                max_sum = max(max_sum, total_sum);
            }
        }
        cout << max_sum << '\n';
    }
    return 0;
}