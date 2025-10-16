#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; char c; string s;
        cin >> n >> c >> s;
        string ss = s + s;
        vector<int> nextG(2 * n, 2 * n);
        int nxt = 2 * n;
        for (int i = 2 * n - 1; i >= 0; --i) {
            if (ss[i] == 'g') nxt = i;
            nextG[i] = nxt;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (ss[i] == c)
                ans = max(ans, nextG[i] - i);
        cout << ans << '\n';
    }
    return 0;
}