#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    long long ans = n + (n - 1) * n * (n + 1) / 6;
    cout << ans;
    return 0;
}