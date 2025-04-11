#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

int dfs(int node, int parent,  vector<vector<int>> &adj){
    int ans=0,cws=adj[node].size();
    int currcnt=1;
    if(parent==-1) cws++;
    while(currcnt<cws){
        ans++;
        currcnt*=2;
    }
    

    for(auto neigh:adj[node]){
        if(neigh!=parent){
            ans+=dfs(neigh,node,adj)+1;
        }
    }

    return ans;
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

    cout<<dfs(0,-1,adj)<<endl;
    return 0;
}