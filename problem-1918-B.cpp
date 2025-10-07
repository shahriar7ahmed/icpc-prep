#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return a[i] < a[j];
        });
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            A[i] = a[idx[i]];
            B[i] = b[idx[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << A[i];
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << B[i];
        }
        cout << '\n';
    }
    return 0;
}