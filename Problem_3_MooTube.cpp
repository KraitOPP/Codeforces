#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(int i, int par, vector<vector<pair<int,int>>> &adj, int k, int &res){
    for(auto neigh: adj[i]){
        if(neigh.first != par && neigh.second >= k){
            res++;
            dfs(neigh.first,i, adj,k,res);
        }
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("mootube.in", "r", stdin);
    int n,q;
    cin>>n>>q;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u-1].push_back({v-1,w});
        adj[v-1].push_back({u-1,w});
    }

    freopen("mootube.out", "w", stdout);
    while(q--){
        int k,v;
        cin>>k>>v;
        int res=0;
        dfs(v-1,-1, adj,k, res);

        cout<<res<<endl;
    }

    return 0;
}