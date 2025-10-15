#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        long long k = (n - 1) / 2;
        long long ans = (4 * k * (k + 1) * (2 * k + 1)) / 3;
        cout << ans << '\n';
    }
    return 0;
}