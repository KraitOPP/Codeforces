#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &subtree, int &ans){
    subtree[node] = 1;
    for(int child: adj[node]){
        if(child != parent){
            dfs(child, node, adj, subtree,ans);
            subtree[node] += subtree[child];
        }
    }
    if(subtree[node]%2==0 && parent!=-1) ans++;

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
    if(n%2==1) cout<<-1<<endl;
    else{
        vector<int> subtree(n,0);
        int ans=0;
        dfs(0,-1,adj,subtree,ans);
        cout<<ans<<endl;
    }


    return 0;
}