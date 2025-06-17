#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

using ll = long long;
using uint = unsigned int;
using state_t = int8_t;

struct Edge {
    int u, v;
    uint w;
};

int main() {
    fastio();
    int n, q;
    cin >> n >> q;

    vector<Edge> edges;
    edges.reserve(q);
    for (int i = 0; i < q; i++) {
        int u, v;
        uint x;
        cin >> u >> v >> x;
        edges.push_back({u - 1, v - 1, x});
    }

    vector<uint> res(n, 0);

    for (int b = 0; b < 30; b++) {
        uint mask = 1u << b;

        vector<vector<int>> adj(n);
        int reserve_sz = max(1, int((2 * q) / n + 1));
        for (auto &nbrs : adj) nbrs.reserve(reserve_sz);

        vector<state_t> state(n, -1); 

        for (auto &e : edges) {
            if (!(e.w & mask)) {
                state[e.u] = state[e.v] = 0;
            } else if (e.u == e.v) {
                state[e.u] = 1;
            } else {
                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
            }
        }

        for (int u = 0; u < n; u++) {
            if (state[u] == 0) {
                for (int v : adj[u]) {
                    if (state[v] < 0) {
                        state[v] = 1;
                    }
                }
            }
        }

        for (int u = 0; u < n; u++) {
            if (state[u] < 0) {
                bool canBeZero = true;
                for (int v : adj[u]) {
                    if (state[v] == 0) {
                        canBeZero = false;
                        break;
                    }
                }
                state[u] = canBeZero ? 0 : 1;
            }
            if (state[u] == 1) {
                res[u] |= mask;
            }
        }
    }

    for (uint x : res) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}