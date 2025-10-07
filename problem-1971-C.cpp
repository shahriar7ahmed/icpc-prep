#include <bits/stdc++.h>
using namespace std;

bool inArc(int from, int to, int x) {
    int cur = from;
    while (true) {
        cur = cur % 12 + 1;
        if (cur == x) return true;
        if (cur == to) break;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool s1 = inArc(a, b, c), s2 = inArc(a, b, d);
        bool s3 = inArc(c, d, a), s4 = inArc(c, d, b);
        cout << ((s1 ^ s2) && (s3 ^ s4) ? "YES\n" : "NO\n");
    }
}