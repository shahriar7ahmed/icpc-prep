#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> parent(n + 1, -1);
        vector<int> dis(n + 1, -1);
        queue<int> q;
        q.push(1);
        dis[1] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        vector<int> parity(n + 1);
        for (int i = 1; i <= n; ++i) {
            parity[i] = dis[i] % 2;
        }
        vector<int> path;
        for (int at = n; at != 1; at = parent[at]) {
            path.push_back(at);
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        int m = path.size();
        vector<string> seq;
        int ones_cnt = 0;
        bool last_is_two = false;
        auto add_one = [&]() {
            seq.push_back("1");
            ++ones_cnt;
            last_is_two = false;
        };
        auto add_destroy = [&](int u) {
            int cur_par = ones_cnt % 2;
            int p_u = parity[u];
            int forb_k_par = p_u ^ cur_par;
            int need_k_par = forb_k_par ^ 1;
            int k;
            if (!last_is_two) {
                k = need_k_par;
            } else {
                k = (need_k_par == 1 ? 1 : 2);
            }
            for (int j = 0; j < k; ++j) {
                add_one();
            }
            seq.push_back("2 " + to_string(u));
            last_is_two = true;
        };
        auto prune = [&](auto&& self, int v, int p) -> void {
            for (int w : adj[v]) {
                if (w != p) {
                    self(self, w, v);
                }
            }
            add_destroy(v);
        };
        int cur_prev = -1;
        if (m > 1) {
            int u = path[0];
            int fwd = path[1];
            for (int v : adj[u]) {
                if (v != cur_prev && v != fwd) {
                    prune(prune, v, u);
                }
            }
            add_one();
            cur_prev = path[0];
        }
        for (int i = 1; i < m - 1; ++i) {
            int u = path[i];
            int fwd = path[i + 1];
            add_destroy(cur_prev);
            for (int v : adj[u]) {
                if (v != cur_prev && v != fwd) {
                    prune(prune, v, u);
                }
            }
            add_one();
            cur_prev = u;
        }
        if (m > 1) {
            add_destroy(cur_prev);
            int u = path.back();
            int prevv = path[m - 2];
            int fwd = -1;
            for (int v : adj[u]) {
                if (v != prevv && v != fwd) {
                    prune(prune, v, u);
                }
            }
        }
        cout << seq.size() << '\n';
        for (const auto& s : seq) {
            cout << s << '\n';
        }
    }
    return 0;
}