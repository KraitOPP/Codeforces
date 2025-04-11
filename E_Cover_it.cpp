#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(vector<vector<int>> &adj,int node,vector<int> &vis,vector<bool> &color, bool isRed){

    vis[node]=1;
    color[node]=isRed;
    for(auto neigh:adj[node]){
        if(!vis[neigh]){
            dfs(adj,neigh,vis,color, !isRed);
        }
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        vector<int> vis(n,0);
        vector<bool> color(n,0);
        dfs(adj,0,vis,color,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(color[i]) cnt++;
        }
        if(cnt>n/2){
            cout<<n-cnt<<endl;
            for(int i=0;i<n;i++){
                if(!color[i]) cout<<i+1<<" ";
            }
        }
        else{
            cout<<cnt<<endl;
            for(int i=0;i<n;i++){
                if(color[i]) cout<<i+1<<" ";
            }
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}