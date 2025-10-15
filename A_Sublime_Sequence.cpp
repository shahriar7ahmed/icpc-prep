#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, n;
        cin >> x >> n;
        cout << (n & 1 ? x : 0) << "\n";
    }
    return 0;
}