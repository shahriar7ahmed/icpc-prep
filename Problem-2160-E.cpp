#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> solve(int n, int m, vector<vector<bool>> C) {
    vector<vector<int>> ans(n, vector<int>(m, LONG_MAX));
    for (int i = 0; i < n; i++) {
        vector<int> mn(m, INT_MAX);
        for (int j = n - 1; j > i; j--) {
            for (int k = 0, prev = -1; k < m; k++) {
                if (C[i][k] && C[j][k]) {
                    if (prev == -1)
                        prev = k;
                    else {
                        for (int l = prev; l <= k; l++)
                            mn[l] = min(mn[l], (j - i + 1) * (k - prev + 1));
                        prev = k;
                    }
                }
            }
            for (int k = 0; k < m; k++) {
                ans[j][k] = min(ans[j][k], mn[k]);
            }
        }
        for (int k = 0; k < m; k++) {
            ans[i][k] = min(ans[i][k], mn[k]);
        }
    }
    return ans;
}
 
template<typename T>
vector<vector<T>> transpose(int n, int m, vector<vector<T>> A) {
    vector<vector<T>> ret(m, vector<T>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ret[j][i] = A[i][j];
    return ret;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector C(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                C[i][j] = s[j] == '1';
        }
        vector<vector<int>> ans;
        if (n > m)
            ans = transpose(m, n, solve(m, n, transpose(n, m, C)));
        else
            ans = solve(n, m, C);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << (ans[i][j] == INT_MAX ? 0 : ans[i][j]) << ' ';
            cout << '\n';
        }
    }
}