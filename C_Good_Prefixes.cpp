#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<long long, int> freq;
        freq.reserve(n * 2);
        freq.max_load_factor(0.7f);
        long long sum = 0;
        int good = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            sum += x;
            ++freq[x];
            if ((sum & 1LL) == 0) {
                long long target = sum / 2;
                if (freq.find(target) != freq.end()) {
                    ++good;
                }
            }
        }
        cout << good << '\n';
    }
    return 0;
}