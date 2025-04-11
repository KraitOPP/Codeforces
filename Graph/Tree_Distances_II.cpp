#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
vector<int> dist(2*1e6+10,0),c(2*1e6+10,0);
int n;

void dfs1(int node, int par, vector<vector<int>> &adj){
    c[node]=1;
    for(auto child: adj[node]){
        if(child!=par){
            dfs1(child,node,adj);
            c[node]+=c[child];
            dist[node]+=dist[child]+c[child];
        }
    }
}

void dfs2(int node, int par, vector<vector<int>> &adj){

    for(auto child: adj[node]){
        if(child!=par){
            dist[child] = dist[node] - c[child] + (n-c[child]);
            dfs2(child,node,adj);
        }
    }
}


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs1(0,-1,adj);
    dfs2(0,-1,adj);

    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
    cout<<endl;


    return 0;
}