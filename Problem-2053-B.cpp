#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;
    void init(int size) {
        n = 1;
        while (n < size) n <<= 1;
        tree.assign(2 * n, INT_MAX);
    }
    void set_val(int pos, int val) {
        pos += n;
        tree[pos] = val;
        for (pos >>= 1; pos; pos >>= 1)
            tree[pos] = min(tree[pos << 1], tree[(pos << 1) | 1]);
    }
    int query(int l, int r) const {
        int res = INT_MAX;
        l += n;
        r += n;
        while (l <= r) {
            if (l & 1) res = min(res, tree[l++]);
            if (!(r & 1)) res = min(res, tree[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> l(n), r(n);
        int maxCoord = 2 * n + 2;
        vector<int> freq(maxCoord + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
            if (l[i] == r[i]) freq[l[i]]++;
        }
        SegTree st;
        st.init(maxCoord + 2);
        for (int i = 0; i <= maxCoord; ++i)
            st.set_val(i, freq[i]);
        string ans(n, '0');
        for (int i = 0; i < n; ++i) {
            if (l[i] == r[i]) {
                ans[i] = (freq[l[i]] == 1) ? '1' : '0';
            } else {
                ans[i] = (st.query(l[i], r[i]) == 0) ? '1' : '0';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}