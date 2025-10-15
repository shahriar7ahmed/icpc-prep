#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        long long cntDash = 0, cntUnd = 0;
        for (char c : s) {
            if (c == '-') ++cntDash;
            else ++cntUnd;
        }
        long long left = cntDash / 2;
        long long right = cntDash - left;
        long long best = left * right;
        cout << cntUnd * best << '\n';
    }
    return 0;
}