#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    long long mn = a.front(), mx = a.back();
    if (mn == mx) {
        cout << 0;
        return 0;
    }
    
    int left = 0, right = n - 1;
    while (left < n && a[left] == mn) ++left;
    while (right >= 0 && a[right] == mx) --right;
    
    int result = max(0, right - left + 1);
    cout << result;
    return 0;
}