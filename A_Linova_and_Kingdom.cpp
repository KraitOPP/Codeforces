#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &dist, vector<int> &subtree){
    subtree[node] = 1;
    for(int child: adj[node]){
        if(child != parent){
            dist[child] = min(dist[child], dist[node] + 1);
            dfs(child, node, adj, dist, subtree);
            subtree[node] += subtree[child];
        }
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> dist(n,inf), subtree(n,0);
    dist[0]=0;
    dfs(0,-1,adj,dist,subtree);


    for(int i=0;i<n;i++){
        // cout<<dist[i]<<" "<<" "<<subtree[i]<<endl;
        dist[i]=dist[i]-subtree[i]+1;

    }
    sort(dist.begin(),dist.end(), greater<int>());
    int res=0;
    
    for(int i=0;i<k;i++){
        res+=dist[i];
    }

    cout<<res<<endl;

    return 0;
}