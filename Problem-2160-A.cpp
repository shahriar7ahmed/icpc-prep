#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        vector<int> freq(102, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        int ans = 101;
        for (int m = 0; m <= 101; m++) {
            bool possible = true;
            if (m == 0) {
                if (freq[0] != 0) possible = false;
            } else {
                if (freq[m] != 0) possible = false;
                for (int i = 0; i < m; i++) {
                    if (freq[i] < 1) possible = false;
                }
            }
            if (possible) ans = min(ans, m);
        }
        cout << ans << endl;
    }
    return 0;
}