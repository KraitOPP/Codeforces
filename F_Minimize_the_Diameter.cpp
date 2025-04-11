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
    int n1;
    cin>>n1;
    vector<vector<int>> adj1(n1);
    for(int i=0;i<n1-1;i++){
        int u,v;
        cin>>u>>v;
        adj1[u-1].push_back(v-1);
        adj1[v-1].push_back(u-1);
    }
    int n2;
    cin>>n2;
    vector<vector<int>> adj2(n2);
    for(int i=0;i<n2;i++){
        int u,v;
        cin>>u>>v;
        adj2[u-1].push_back(v-1);
        adj2[v-1].push_back(u-1);
    }

    pair<int,int> a1 = diam(0,-1,adj1,0);
    pair<int,int> dia1 = diam(a1.first,-1,adj1,0);
    pair<int,int> a2 = diam(0,-1,adj2,0);
    pair<int,int> dia2 = diam(a2.first,-1,adj2,0);

    cout<<max(max(dia1.second,dia2.second), (dia1.second+1)/2+(dia2.second+1)/2+1)<<endl;

    return 0;
}