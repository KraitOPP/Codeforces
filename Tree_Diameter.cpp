#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

pair<int,int> diam(int node, int parent, vector<vector<int>> &adj, int len){
    pair<int,int> mxpath = {node,len};

    for(auto neigh: adj[node]){
        if(neigh==parent) continue;
        pair<int,int> other = diam(neigh,node,adj,len+1);
        if(other.second > mxpath.second){
            mxpath = other;
        }
    }

    return mxpath;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    pair<int,int> a = diam(0,-1,adj,0);
    pair<int,int> dia = diam(a.first,-1,adj,0);

    cout<<dia.second<<endl;

    return 0;
}