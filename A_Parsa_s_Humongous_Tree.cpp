#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<vector<int>> &dp, vector<pair<int,int>> &a){
    for(int child: adj[node]){
        if(child != parent){
            dfs(child, node, adj, dp, a);
            dp[node][0] += max(dp[child][0]+abs(a[node].first-a[child].first), dp[child][1]+abs(a[node].first-a[child].second));
            dp[node][1] += max(dp[child][0]+abs(a[node].second-a[child].first), dp[child][1]+abs(a[node].second-a[child].second));
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
        int n;
        cin>>n;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        vector<vector<int>> dp(n,vector<int>(2,0));
        dfs(0,-1,adj,dp,a);
        int res=0;

        cout<<max(dp[0][0],dp[0][1])<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}