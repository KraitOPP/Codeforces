#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18, mod = 1e9 + 7;
int n, m;

void dfs(int node, vector<vector<int>>& adjList, vector<int>& vis) {
    vis[node] = true;
    for (auto neighbor : adjList[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adjList, vis);
        }
    }
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 10;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();

        cin >> n >> m;
        if (n == 0 && m == 0) exit(0);
        
        vector<vector<int>> adjList(n);
        vector<pair<int, int>> edges;
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        bool res = false;
        
        vector<int> vis(n, 0);
        dfs(0, adjList, vis);
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) cnt++;
        }
        
        if (cnt != n) { 
            res = true;
        } else {
            for (int i = 0; i < m; i++) {
                int u = edges[i].first;
                int v = edges[i].second;

                adjList[u].erase(find(adjList[u].begin(), adjList[u].end(), v));
                adjList[v].erase(find(adjList[v].begin(), adjList[v].end(), u));

                fill(vis.begin(), vis.end(), 0);  
                dfs(0, adjList, vis);

                cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (vis[i]) cnt++;
                }

                if (cnt != n) {
                    res = true;
                    break;
                }

                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    
    return 0;
}
