#include <bits/stdc++.h>
namespace boost {
namespace multiprecision {
using int128_t = __int128_t;
}
}
using namespace std;

using int64 = long long;
using i128 = boost::multiprecision::int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int64 c;
        cin >> n >> c;
        vector<int64> s(n);
        for (auto &x : s) cin >> x;
        auto calc = [&](int64 w) -> i128 {
            i128 cap = c, sum = 0;
            for (int64 side : s) {
                i128 len = side + (i128)2 * w;
                sum += len * len;
                if (sum > cap) break;
            }
            return sum;
        };
        int64 lo = 0, hi = 1;
        while (calc(hi) < c) hi <<= 1;
        while (lo < hi) {
            int64 mid = lo + ((hi - lo) >> 1);
            if (calc(mid) >= c) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
    return 0;
}