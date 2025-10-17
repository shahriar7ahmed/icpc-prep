#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long sum_p_total = (long long)n * (n + 1) / 2;
    cout << "2 1 " << n << endl;
    long long sum_a_total;
    cin >> sum_a_total;

    long long k = sum_a_total - sum_p_total;

    long long low = 1, high = n;
    long long r = n; 
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid < 1) { 
            low = mid + 1;
            continue;
        }

        cout << "1 1 " << mid << endl;
        long long sp_prefix;
        cin >> sp_prefix;

        cout << "2 1 " << mid << endl;
        long long sa_prefix;
        cin >> sa_prefix;

        long long diff = sa_prefix - sp_prefix;

        if (diff == k) {
            r = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    long long l = r - k + 1;
    cout << "! " << l << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}