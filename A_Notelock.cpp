#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> ones;
        for (int i = 0; i < n; ++i)
            if (s[i] == '1') ones.push_back(i);
        if (ones.empty()) {
            cout << 0 << '\n';
            continue;
        }
        int res = 1;
        for (size_t i = 1; i < ones.size(); ++i)
            if (ones[i] - ones[i - 1] >= k) ++res;
        cout << res << '\n';
    }
    return 0;
}