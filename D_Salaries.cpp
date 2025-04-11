#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18, mod = 1e9+7;

void dfsHeight(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &height){
    vis[node] = 1;
    int heigh = 1;
    for(auto child : adj[node]){
        if(!vis[child]){
            dfsHeight(child, adj, vis, height);
        }
        heigh = max(heigh, height[child] + 1);
    }
    height[node] = heigh;
}

void dfs2(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &height){
    vis[node] = 1;
    int mxheigh = 0, mxchild = -1;
    for(auto child : adj[node]){
        if(mxheigh < height[child]){
            mxheigh = height[child];
            mxchild = child;
        }
    }

    if(mxchild != -1){
        dfs2(mxchild, vis, adj, height);
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++){
        int u;
        cin >> u;
        adj[u].push_back(i);
    }

    vector<int> height(n + 1, 0);
    vector<int> vis(n + 1, 0);
    dfsHeight(1, adj, vis, height);
    fill(vis.begin(), vis.end(), 0);
    priority_queue<pair<int, int>> pq;
    int cnt = 0;
    int res = 0;
    for(int i = 1; i <= n; i++){
        pq.push({height[i], i});
    }
    while(!pq.empty() && cnt < k){
        while(!pq.empty() && vis[pq.top().second] != 0) pq.pop();
        if(pq.empty()) break;
        res += pq.top().first;
        dfs2(pq.top().second, vis, adj, height);
        cnt++;
    }

    cout << res << endl;

    return 0;
}
