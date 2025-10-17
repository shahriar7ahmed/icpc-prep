#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long q = (n + k - 1) / k;
        long long total = q * k;
        long long ans = (total + n - 1) / n;
        cout << ans << '\n';
    }
    return 0;
}