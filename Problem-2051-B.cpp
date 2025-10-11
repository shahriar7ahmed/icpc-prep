#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        long long cycle = a + b + c;
        long long full_cycles = (n - 1) / cycle;
        long long days = full_cycles * 3;
        long long rem = n - full_cycles * cycle;
        if (rem <= a) {
            cout << days + 1 << '\n';
        } else if (rem <= a + b) {
            cout << days + 2 << '\n';
        } else {
            cout << days + 3 << '\n';
        }
    }
    return 0;
}