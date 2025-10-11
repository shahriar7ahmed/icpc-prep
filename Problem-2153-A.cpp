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
        vector<int> b(n);
        vector<bool> seen(n + 1, false);
        int distinct = 0;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if (!seen[b[i]]) {
                seen[b[i]] = true;
                ++distinct;
            }
        }
        cout << distinct << '\n';
    }
    return 0;
}