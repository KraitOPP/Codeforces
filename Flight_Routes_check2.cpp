#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define vi vector<int>
const int inf = 1e18, mod = 1e9 + 7;
int n, m, timer = 0;
stack<int> s;
vector<vector<int>> sccs;

void dfs(vector<vector<int>> &adj, int node, vector<int> &vis, vector<int> &arr, vector<int> &low, vector<int> &instack) {
    vis[node] = true;
    low[node] = arr[node] = timer++;
    s.push(node);
    instack[node] = true;

    for (auto neigh : adj[node]) {
        if (!vis[neigh]) {
            dfs(adj, neigh, vis, arr, low, instack);
            low[node] = min(low[node], low[neigh]);
        }
        else if (instack[neigh]) {
            low[node] = min(low[node], arr[neigh]);
        }
    }

    if (low[node] == arr[node]) {
        vector<int> scc;
        while (true) {
            int top = s.top();
            s.pop();
            instack[top] = false;
            scc.push_back(top);
            if (top == node) break;
        }
        sccs.push_back(scc);  
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> vis(n + 1, 0), low(n + 1), arr(n + 1), instack(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(adj, i, vis, arr, low, instack);
        }
    }

    if (sccs.size() == 1) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;  
        cout << sccs[0][0] << " " << sccs[1][0] << endl;
    }

    return 0;
}
