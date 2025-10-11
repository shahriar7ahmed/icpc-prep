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
        unordered_map<long long, long long> freq;
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;
            long long key = x - i;
            ans += freq[key];
            ++freq[key];
        }
        cout << ans << '\n';
    }
    return 0;
}