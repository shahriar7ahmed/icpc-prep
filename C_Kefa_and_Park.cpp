#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> cat(n + 1);
    for (int i = 1; i <= n; ++i) cin >> cat[i];
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<char> vis(n + 1, 0);
    vector<pair<int, int>> st;
    st.push_back({1, cat[1]});
    vis[1] = 1;
    long long ans = 0;
    
    while (!st.empty()) {
        auto [node, consec] = st.back();
        st.pop_back();
        if (consec > m) continue;
        bool isLeaf = true;
        for (int nei : adj[node]) {
            if (!vis[nei]) {
                isLeaf = false;
                vis[nei] = 1;
                int nextConsec = cat[nei] ? consec + 1 : 0;
                st.push_back({nei, nextConsec});
            }
        }
        if (isLeaf) ++ans;
    }
    
    cout << ans << '\n';
    return 0;
}