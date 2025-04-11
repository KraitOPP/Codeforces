#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(vector<vector<int>> &adj,int i,vector<int> &vis){
    vis[i]=1;
    for(auto j:adj[i]){
        if(!vis[j]){
            dfs(adj,j,vis);
        }
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        int n;
        cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int v;
            cin>>v;
            v--;
            adj[i].push_back(v);
            adj[v].push_back(i);
        }


        vector<int> vis(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                res++;
            }
        }

        cout<<res<<endl;

    return 0;
}