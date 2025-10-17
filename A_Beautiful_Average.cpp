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
        int best = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            best = max(best, x);
        }
        cout << best << '\n';
    }
    return 0;
}