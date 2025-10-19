#include <bits/stdc++.h>
using namespace std;

const int MAXV = 200000 + 5;
vector<int> spf(MAXV + 1);

void build_spf() {
    for (int i = 0; i <= MAXV; ++i) spf[i] = i;
    spf[0] = 0;
    spf[1] = 1;
    for (int i = 2; i * i <= MAXV; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXV; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> get_factors(int x) {
    vector<int> res;
    while (x > 1) {
        int p = spf[x];
        res.push_back(p);
        while (x % p == 0) x /= p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build_spf();
    vector<int> freq(MAXV + 1, 0);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) {
            int dummy;
            cin >> dummy;
        }
        vector<int> touched;
        touched.reserve(n * 3);
        for (int x : a) {
            vector<int> factors = get_factors(x);
            for (int p : factors) {
                if (freq[p] == 0) touched.push_back(p);
                ++freq[p];
            }
        }
        int ans = 2;
        for (int p : touched) {
            if (freq[p] >= 2) {
                ans = 0;
                break;
            }
        }
        if (ans != 0) {
            bool one = false;
            for (int x : a) {
                vector<int> factors = get_factors(x + 1);
                for (int p : factors) {
                    if (freq[p] > 0) {
                        one = true;
                        break;
                    }
                }
                if (one) break;
            }
            if (one) ans = 1;
        }
        cout << ans << '\n';
        for (int p : touched) freq[p] = 0;
    }
    return 0;
}