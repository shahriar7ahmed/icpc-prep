#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string w;
        long long p;
        cin >> w >> p;
        vector<int> freq(26, 0);
        long long total = 0;
        for (char c : w) {
            int idx = c - 'a';
            freq[idx]++;
            total += idx + 1;
        }
        if (total <= p) {
            cout << w << '\n';
            continue;
        }
        vector<int> remove(26, 0);
        for (int i = 25; i >= 0 && total > p; --i) {
            while (freq[i] > 0 && total > p) {
                freq[i]--;
                remove[i]++;
                total -= i + 1;
            }
        }
        string result;
        result.reserve(w.size());
        for (char c : w) {
            int idx = c - 'a';
            if (remove[idx] > 0) {
                --remove[idx];
            } else {
                result.push_back(c);
            }
        }
        cout << result << '\n';
    }
    return 0;
}