#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        cin >> n;

        vector<long long> a(n + 2), pref(n + 2);

        for (int i = 1; i <= n; ++i) 
        {
            cin >> a[i];
            pref[i] = (i == 1) ? a[i] : max(pref[i - 1], a[i]);
        }

        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }

        long long ans = 0;

        for (int i = 1; i <= n; i += 2) 
        {
            long long limit = (i == 1) ? pref[2] - 1 : pref[i - 1] - 1;
            if (a[i] > limit) ans += a[i] - limit;
        }
        cout << ans << '\n';
    }
    return 0;
}