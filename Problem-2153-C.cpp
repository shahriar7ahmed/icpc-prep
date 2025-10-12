#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long solve_test_case() {
    int n;
    cin >> n;
    
    vector<long long> sticks(n);
    map<long long, int> freq;
    
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
        freq[sticks[i]]++;
    }
    
    // Try different combinations of sticks on the symmetry line
    long long max_perimeter = 0;
    
    // Try with no sticks on symmetry line
    vector<long long> pairs;
    long long pair_sum = 0;
    
    for (auto &p : freq) {
        int pair_count = p.second / 2;
        for (int i = 0; i < pair_count; i++) {
            pairs.push_back(p.first);
            pair_sum += 2 * p.first;
        }
    }
    
    // Check if valid with no sticks on symmetry line
    if (pairs.size() >= 2) {  // Need at least 2 pairs for a valid polygon
        sort(pairs.begin(), pairs.end());
        if (pairs.back() < pair_sum - pairs.back()) {  // Convexity check
            max_perimeter = max(max_perimeter, pair_sum);
        }
    }
    
    // Try with sticks on symmetry line
    for (auto &s1 : freq) {
        if (s1.second > 0) {
            // Try with one stick on symmetry line
            vector<long long> remaining_pairs;
            long long remaining_sum = s1.first;
            
            for (auto &p : freq) {
                int count = p.second;
                if (p.first == s1.first) count--;
                
                int pair_count = count / 2;
                for (int i = 0; i < pair_count; i++) {
                    remaining_pairs.push_back(p.first);
                    remaining_sum += 2 * p.first;
                }
            }
            
            if (remaining_pairs.size() >= 1) {  // Need at least 1 pair with 1 stick on symmetry
                sort(remaining_pairs.begin(), remaining_pairs.end());
                if (remaining_pairs.back() < remaining_sum - remaining_pairs.back()) {  // Convexity check
                    max_perimeter = max(max_perimeter, remaining_sum);
                }
            }
            
            // Try with two sticks on symmetry line
            for (auto &s2 : freq) {
                if ((s1 == s2 && s1.second > 1) || (s1 != s2 && s2.second > 0)) {
                    vector<long long> pairs_with_two;
                    long long sum_with_two = s1.first + s2.first;
                    
                    for (auto &p : freq) {
                        int count = p.second;
                        if (p.first == s1.first) count--;
                        if (p.first == s2.first) count--;
                        
                        int pair_count = count / 2;
                        for (int i = 0; i < pair_count; i++) {
                            pairs_with_two.push_back(p.first);
                            sum_with_two += 2 * p.first;
                        }
                    }
                    
                    if (pairs_with_two.size() >= 1) {  // Need at least 1 pair with 2 sticks on symmetry
                        sort(pairs_with_two.begin(), pairs_with_two.end());
                        long long max_side = max(pairs_with_two.back(), max(s1.first, s2.first));
                        if (max_side < sum_with_two - max_side) {  // Convexity check
                            max_perimeter = max(max_perimeter, sum_with_two);
                        }
                    }
                }
            }
        }
    }
    
    return max_perimeter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        cout << solve_test_case() << endl;
    }
    
    return 0;
}
