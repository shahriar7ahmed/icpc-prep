#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + a[i];
        ll base = pref[n];
        ll best = base; // at least original sum

        for (int i = 0; i < n; ++i) {
            int left_count = i;           // number of elements strictly to the left
            int right_count = n - 1 - i;  // number of elements strictly to the right
            int y_max = min(left_count, right_count);
            if (y_max == 0) continue; // no effect with y=0

            auto gain_for_y = [&](int y) -> ll {
                ll t = min<ll>(k * y, left_count); // number of left-most elements we can raise
                // gain = ai*(t + y) - sum(first t) - sum(a[i+1 .. i+y])
                ll ai = a[i];
                ll left_sum = pref[t];
                ll right_sum = pref[i + y + 1] - pref[i + 1];
                return ai * (t + y) - left_sum - right_sum;
            };

            auto delta_for_y = [&](int y) -> ll {
                // delta = gain(y) - gain(y-1), defined for y >= 1
                ll ai = a[i];
                ll t_prev = min<ll>(k * (y - 1), left_count);
                ll t = min<ll>(k * y, left_count);
                ll delta_t = t - t_prev;
                ll sum_new_increases = pref[t] - pref[t_prev];
                ll lost = a[i + y]; // the newly forced decreased element
                // delta = ai*(delta_t + 1) - sum_new_increases - lost
                return ai * (delta_t + 1) - sum_new_increases - lost;
            };

            // Binary search highest y in [1..y_max] with delta(y) > 0
            int l = 1, r = y_max;
            int found = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (delta_for_y(mid) > 0) {
                    found = mid; // mid is possible, try higher
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            int y_best = found; // 0 if none positive
            ll gain = (y_best == 0 ? 0 : gain_for_y(y_best));
            best = max(best, base + gain);
        }

        cout << best << '\n';
    }
    return 0;
}