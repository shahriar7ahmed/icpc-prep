#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<int> a(n);
        map<int, int> last_to_v;
        int next_v = 1;
        for (int i = 1; i <= n; ++i) {
            long long s = (i == 1 ? b[0] : b[i - 1] - b[i - 2]);
            int r = s - 1;
            int target = i - 1 - r;
            if (last_to_v.count(target)) {
                int v = last_to_v[target];
                a[i - 1] = v;
                last_to_v.erase(target);
                last_to_v[i] = v;
            } else {
                int v = next_v++;
                a[i - 1] = v;
                last_to_v[i] = v;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << "\n";
    }
    return 0;
}