#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        
        vector<vector<int>> result(n, vector<int>(m, 0));
        
        vector<tuple<int, int, int, int, int>> rectangles; 
        
        for (int u = 0; u < n; u++) {
            for (int d = u + 1; d < n; d++) {
                for (int l = 0; l < m; l++) {
                    for (int r = l + 1; r < m; r++) {
                        if (grid[u][l] == '1' && grid[u][r] == '1' && 
                            grid[d][l] == '1' && grid[d][r] == '1') {
                            int area = (d - u + 1) * (r - l + 1);
                            rectangles.push_back({area, u, d, l, r});
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int minArea = INT_MAX;
                
                for (auto& [area, u, d, l, r] : rectangles) {
                    if (u <= i && i <= d && l <= j && j <= r) {
                        minArea = min(minArea, area);
                    }
                }
                
                if (minArea != INT_MAX) {
                    result[i][j] = minArea;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << result[i][j];
                if (j < m - 1) cout << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}