#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const ll INF = 4e18;
const int N = 200000 + 5;
 
vector<int> spf(N + 1);
pair<ll, ll> mn[N + 1];
vector<int> used;
 
void sieve() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= N; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
 
void factors(int x, set<int> &st) {
    while (x > 1) {
        int p = spf[x];
        st.insert(p);
        while (x % p == 0) x /= p;
    }
}
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
 
    set<int> s;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) factors(a[i] - 1, s);
        factors(a[i], s);
        factors(a[i] + 1, s);
    }
    
    for (int p : s) {
        if (mn[p].first != INF) mn[p] = {INF, INF};
        else {
            used.push_back(p);
            mn[p] = {INF, INF};
        }
    }
 
    for (int p : s) {
        for (int i = 0; i < n; ++i) {
            ll k = (a[i] % p == 0) ? 0 : (ll)p - (a[i] % p);
            ll cost = k * c[i];
            if (cost < mn[p].first) {
                mn[p].second = mn[p].first;
                mn[p].first = cost;
            } else if (cost < mn[p].second) {
                mn[p].second = cost;
            }
        }
    }
 
    ll ans = INF;
    for (int p : s) {
        if (mn[p].second != INF)
            ans = min(ans, mn[p].first + mn[p].second);
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    sieve();
    for (int i = 0; i <= N; ++i) mn[i] = {INF, INF};
 
    int t; cin >> t;
    while (t--) solve();
 
    for (int p : used) mn[p] = {INF, INF};
}