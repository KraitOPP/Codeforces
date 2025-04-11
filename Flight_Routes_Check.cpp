#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define vi vector<int>
const int inf = 1e18, mod = 1e9 + 7;
int n, m;
stack<int> s;

void dfs(vector<vector<int>> &adj, int node, vector<int> &vis) {
    vis[node] = true;
    for (auto neigh : adj[node]) {
        if (!vis[neigh]) {
            dfs(adj, neigh, vis);
        }
    }
    s.push(node); 
}

void revdfs(vector<vector<int>> &revadj, int node, vector<int> &vis, int comp, vector<vector<int>> &components) {
    vis[node] = true;
    components[comp].push_back(node);
    for (auto neigh : revadj[node]) {
        if (!vis[neigh]) {
            revdfs(revadj, neigh, vis, comp, components);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> adj(n + 1), revadj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revadj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(adj, i, vis);
        }
    }

    fill(vis.begin(), vis.end(), 0);  
    int comp = 0;
    vector<vector<int>> components(n); 

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!vis[node]) {
            revdfs(revadj, node, vis, comp, components);
            comp++;  
        }
    }

    if (comp == 1) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;  
        cout << components[0][0] << " " << components[1][0] << endl;
    }

    return 0;
}
