#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18, mod = 1e9 + 7, N = 2500 + 10;
int n, m;
vector<int> adj[N];

int bfs(int src){
    queue<int> q;
    q.push(src);
    vector<int> dist(N, inf);
    dist[src] = 0;
    int res=inf;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == inf) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            else if (dist[v] >= dist[u]) { 
                res=min(dist[v] + dist[u] + 1,res);
            }
        }
    }
    return res; 
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int res = inf;
    for (int i = 1; i <= n; i++) {
        res = min(res, bfs(i));
    }

    if (res == inf) res = -1;
    cout << res << endl;

    return 0;
}
