#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, int> freq;
    for (int x : a) {
        freq[x]++;
    }
    
    long long max_perimeter = 0;
    
    for (auto& [middle, cnt] : freq) {
        vector<int> pairs;
        long long total = middle;
        
        for (auto& [length, count] : freq) {
            int available = count;
            if (length == middle) {
                available = count - 1;
            }
            
            int pairs_count = available / 2;
            for (int i = 0; i < pairs_count; i++) {
                pairs.push_back(length);
                total += (long long)length * 2;
            }
        }
        
        if (pairs.size() >= 1) {
            vector<long long> all_sides;
            all_sides.push_back(middle);
            for (int p : pairs) {
                all_sides.push_back(p);
                all_sides.push_back(p); 
            }
            
            sort(all_sides.begin(), all_sides.end(), greater<long long>());
            
            long long longest = all_sides[0];
            long long sum_others = 0;
            for (int i = 1; i < all_sides.size(); i++) {
                sum_others += all_sides[i];
            }
            
            if (longest < sum_others) {
                max_perimeter = max(max_perimeter, total);
            }
        }
    }
    
    vector<int> pairs;
    long long total = 0;
    
    for (auto& [length, count] : freq) {
        int pairs_count = count / 2;
        for (int i = 0; i < pairs_count; i++) {
            pairs.push_back(length);
            total += (long long)length * 2;
        }
    }
    
    if (pairs.size() >= 2) {
        
        vector<long long> all_sides;
        for (int p : pairs) {
            all_sides.push_back(p);
            all_sides.push_back(p); 
        }
        
        sort(all_sides.begin(), all_sides.end(), greater<long long>());
        
        long long longest = all_sides[0];
        long long sum_others = 0;
        for (int i = 1; i < all_sides.size(); i++) {
            sum_others += all_sides[i];
        }
        
        if (longest < sum_others) {
            max_perimeter = max(max_perimeter, total);
        }
    }
    
    cout << max_perimeter << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}