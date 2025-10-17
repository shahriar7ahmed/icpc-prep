#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(const string &x) {
    int i = 0, j = (int)x.size() - 1;
    while (i < j) {
        if (x[i] != x[j]) return false;
        ++i; --j;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool found = false;
        vector<int> answer;

        for (int mask = 0; mask < (1 << n) && !found; ++mask) {
            bool ok = true;
            bool seen1 = false;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    char c = s[i];
                    if (seen1 && c == '0') {
                        ok = false; 
                        break;
                    }
                    if (c == '1') seen1 = true;
                }
            }
            if (!ok) continue;

            string x;
            x.reserve(n);
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) x.push_back(s[i]);
            }

            if (is_palindrome(x)) {
                found = true;
                answer.clear();
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) answer.push_back(i + 1); 
                }
                cout << (int)answer.size() << '\n';
                if (!answer.empty()) {
                    for (int i = 0; i < (int)answer.size(); ++i) {
                        if (i) cout << ' ';
                        cout << answer[i];
                    }
                    cout << '\n';
                } else {
                    cout << '\n';
                }
            }
        }

        if (!found) {
            cout << -1 << '\n';
        }
    }

    return 0;
}