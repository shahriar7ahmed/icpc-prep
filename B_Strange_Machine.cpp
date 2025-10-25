#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<long long> queries(q);
        for (int i = 0; i < q; ++i) cin >> queries[i];
        bool allA = true;
        for (char c : s) if (c == 'B') { allA = false; break; }
        vector<int> runLen(n, 0);
        if (!allA) {
            for (int i = 0; i < n; ++i) if (s[i] == 'A') {
                int len = 0;
                while (len < n && s[(i + len) % n] == 'A') ++len;
                runLen[i] = len;
            }
        }
        for (long long x : queries) {
            if (allA) {
                cout << x << "\n";
                continue;
            }
            long long steps = 0;
            int pos = 0;
            while (x > 0) {
                if (s[pos] == 'A') {
                    int len = runLen[pos];
                    if (x <= len) {
                        steps += x;
                        x = 0;
                    } else {
                        x -= len;
                        steps += len;
                        pos = (pos + len) % n;
                    }
                } else {
                    ++steps;
                    x >>= 1;
                    pos = (pos + 1) % n;
                }
            }
            cout << steps << "\n";
        }
    }
    return 0;
}