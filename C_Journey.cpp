#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(int i, vector<int> &vis, vector<vector<int>> &adj, int curr, double prob, double &ans){
    vis[i]=1;

    int res=0, pos=0;
    for(auto x:adj[i]){
        if(!vis[x]){
            pos++;
        }
    }

    if(pos==0){
        ans+=curr*prob;
    }
    else{
        for(auto neigh:adj[i]){
            if(!vis[neigh]){
                dfs(neigh,vis,adj,curr+1,prob*(1.0/pos),ans);
            }
        }
    }

    return;
}

void solve(){
    int n;
    cin>>n;

    if(n==1){
        cout<<0<<endl;
        return;
    }

    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector<int> vis(n,0);
    double ans=0;
    dfs(0,vis,adj,0,1.0, ans);
    cout << setprecision(10) << ans << endl;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}