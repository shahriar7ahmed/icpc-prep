#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        bool ok = true;
        for (int bit = 0; bit < 31 && ok; ++bit) {
            int xb = (x >> bit) & 1;
            int yb = (y >> bit) & 1;
            int zb = (z >> bit) & 1;
            if (!((xb == 0 && yb == 0 && zb == 0) ||
                  (xb == 0 && yb == 1 && zb == 0) ||
                  (xb == 0 && yb == 0 && zb == 1) ||
                  (xb == 1 && yb == 0 && zb == 0) ||
                  (xb == 1 && yb == 1 && zb == 1))) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}