#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        unordered_map<int, int> total_count;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total_count[a[i]]++;
        }
        
        bool possible = true;
        unordered_map<int, int> max_allowed;
        for (auto& p : total_count) {
            if (p.second % k != 0) {
                possible = false;
                break;
            }
            max_allowed[p.first] = p.second / k;
        }
        
        if (!possible) {
            cout << 0 << "\n";
            continue;
        }
        
        long long ans = 0;
        
        int r = 0;
        unordered_map<int, int> count;
        
        for (int l = 0; l < n; l++) {
            while (r < n && count[a[r]] + 1 <= max_allowed[a[r]]) {
                count[a[r]]++;
                r++;
            }
            
            ans += r - l;
            
            if (l < r) {
                count[a[l]]--;
                if (count[a[l]] == 0) {
                    count.erase(a[l]);
                }
            } else {
                r = l + 1;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}