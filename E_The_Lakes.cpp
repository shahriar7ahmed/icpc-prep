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
        int total = n * m;
        vector<int> a(total);
        for (int i = 0; i < total; ++i) cin >> a[i];
        vector<char> seen(total, 0);
        long long best = 0;
        vector<int> stack;
        stack.reserve(total);
        for (int idx = 0; idx < total; ++idx) {
            if (a[idx] == 0 || seen[idx]) continue;
            long long volume = 0;
            stack.push_back(idx);
            seen[idx] = 1;
            while (!stack.empty()) {
                int v = stack.back();
                stack.pop_back();
                volume += a[v];
                int r = v / m, c = v % m;
                if (r && !seen[v - m] && a[v - m] > 0) {
                    seen[v - m] = 1;
                    stack.push_back(v - m);
                }
                if (r + 1 < n && !seen[v + m] && a[v + m] > 0) {
                    seen[v + m] = 1;
                    stack.push_back(v + m);
                }
                if (c && !seen[v - 1] && a[v - 1] > 0) {
                    seen[v - 1] = 1;
                    stack.push_back(v - 1);
                }
                if (c + 1 < m && !seen[v + 1] && a[v + 1] > 0) {
                    seen[v + 1] = 1;
                    stack.push_back(v + 1);
                }
            }
            best = max(best, volume);
        }
        cout << best << '\n';
    }
    return 0;
}