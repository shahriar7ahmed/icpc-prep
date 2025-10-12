#include <bits/stdc++.h>
using namespace std;

bool possible(uint32_t n) {
    if (n == 0) return true;
    string s;
    while (n) {
        s.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    int tz = 0;
    while (tz < (int)s.size() && s[s.size() - 1 - tz] == '0') ++tz;
    for (int k = 0; k <= tz; ++k) {
        int len = (int)s.size() - k;
        bool pal = true;
        for (int i = 0; i < len / 2; ++i) {
            if (s[i] != s[len - 1 - i]) {
                pal = false;
                break;
            }
        }
        if (!pal) continue;
        if (len % 2 == 1 && s[len / 2] != '0') continue;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        uint32_t n;
        cin >> n;
        cout << (possible(n) ? "YES" : "NO") << '\n';
    }
    return 0;
}