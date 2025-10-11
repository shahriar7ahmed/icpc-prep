#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    int words = (N + 63) >> 6;
    vector<vector<uint64_t>> adj(N, vector<uint64_t>(words, 0));
    vector<int> self(N, 0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            int val;
            cin >> val;
            if (val) {
                adj[i][j >> 6] |= 1ull << (j & 63);
                if (i == j) self[i] = 1;
            }
        }
    vector<uint64_t> baseMask(words, ~0ull);
    if ((N & 63) != 0) baseMask.back() = (1ull << (N & 63)) - 1;
    const int INF = N + N + 5;
    vector<int> dist(N, INF), result(N, -1);
    vector<uint64_t> unvisited(words);
    vector<int> q;
    q.reserve(N);
    for (int s = 0; s < N; ++s) {
        if (self[s]) {
            result[s] = 1;
            continue;
        }
        fill(dist.begin(), dist.end(), INF);
        unvisited = baseMask;
        int sWord = s >> 6;
        uint64_t sMask = 1ull << (s & 63);
        unvisited[sWord] &= ~sMask;
        dist[s] = 0;
        q.clear();
        q.push_back(s);
        int best = INF;
        for (size_t head = 0; head < q.size(); ++head) {
            int u = q[head];
            int du = dist[u];
            if (du + 1 >= best) continue;
            for (int w = 0; w < words; ++w) {
                uint64_t bits = adj[u][w] & unvisited[w];
                while (bits) {
                    int bit = __builtin_ctzll(bits);
                    bits &= bits - 1;
                    int v = (w << 6) + bit;
                    unvisited[w] &= ~(1ull << bit);
                    int dv = du + 1;
                    dist[v] = dv;
                    if (adj[v][sWord] & sMask) {
                        int cand = dv + 1;
                        if (cand < best) best = cand;
                    }
                    if (dv + 1 < best) q.push_back(v);
                }
            }
        }
        if (best < INF) result[s] = best;
    }
    for (int i = 0; i < N; ++i) {
        if (result[i] == -1) cout << "NO WAY\n";
        else cout << result[i] << '\n';
    }
    return 0;
}