
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; i++) {
            int last = a.back();
            int last2 = (a.size() >= 2 ? a[a.size() - 2] : -1);
            int x = -1;

            for (int c = 1; c <= 3; c++) {
                if (c != last && c != last2) {
                    x = c;
                    break;
                }
            }
            
            if (x == -1) {
                for (int c = 1; c <= n; c++) {
                    if (c != last && c != last2) {
                        x = c;
                        break;
                    }
                }
            }
            a.push_back(x);
            res.push_back(x);
        }

        for (int i = 0; i < k; i++) {
            if (i) cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}