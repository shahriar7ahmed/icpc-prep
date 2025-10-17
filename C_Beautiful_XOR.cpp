#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long a, b;
        cin >> a >> b;
 
        if (a == b) {
            cout << 0 << '\n';
            continue;
        }
 
        auto msb = [](long long x) -> int {
            return 63 - __builtin_clzll((unsigned long long)x);
        };
        if (msb(b) > msb(a)) {
            cout << -1 << '\n';
            continue;
        }
 
        long long x = (a ^ b);
        if (x <= a) {
            cout << 1 << '\n' << x << '\n';
            continue;
        }
 
       
        int k = msb(a);
        long long W = (1LL << (k + 1)) - 1;
        long long x1 = W - a;
        long long x2 = W ^ b;
 
  
 
        cout << 2 << '\n' << x1 << ' ' << x2 << '\n';
    }
    return 0;
}