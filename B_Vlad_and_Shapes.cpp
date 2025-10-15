#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (auto &row : grid) cin >> row;
        int minR = n, minC = n, maxR = -1, maxC = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') {
                    minR = min(minR, i);
                    minC = min(minC, j);
                    maxR = max(maxR, i);
                    maxC = max(maxC, j);
                }
        int height = maxR - minR + 1;
        int width = maxC - minC + 1;
        bool square = (height == width) && height > 1;
        if (square) {
            for (int i = minR; i <= maxR && square; ++i)
                for (int j = minC; j <= maxC; ++j)
                    if (grid[i][j] != '1') {
                        square = false;
                        break;
                    }
        }
        cout << (square ? "SQUARE" : "TRIANGLE") << '\n';
    }
    return 0;
}