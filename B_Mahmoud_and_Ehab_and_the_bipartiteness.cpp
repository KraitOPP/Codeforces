#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

void dfs(vector<vector<int>> &adj, int node, bool isR, vector<bool> &red, vector<bool> &vis){
    if(isR) red[node]=true;
    vis[node]=true;

    for(auto neigh:adj[node]){
        if(vis[neigh]==false){
            dfs(adj,neigh,!isR,red,vis);
        }
    }
    return;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> red(n+1,false);
        vector<bool> vis(n+1,false);
        int l=0,r=0;
        dfs(adj,1,true,red,vis);
        for(int i=1;i<=n;i++){
            if(red[i]==true) l++;
            else r++;
        }
        int res=l*r-(n-1);
        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    
    return 0;
}