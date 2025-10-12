#include <bits/stdc++.h>
using namespace std;
 
int qu(vector<int> v) {
    cout << "? " << v.size() << ' ';
    for (int x : v)
        cout << x << ' ';
    cout << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> in(2 * n);
        vector<int> v, sv, a(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) {
            v.push_back(i);
            int ret = qu(v);
            if (ret) {
                v.pop_back();
                sv.push_back(i);
                a[i] = ret;
                in[i] = true;
            }
        }
        for (int i = 1; i <= 2 * n; i++) {
            if (!in[i]) {
                sv.push_back(i);
                a[i] = qu(sv);
                sv.pop_back();
            }
        }
        cout << "! ";
        for (int i = 1; i <= 2 * n; i++)
            cout << a[i] << ' ';
        cout << endl;
        cout.flush();
    }
}