#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

bool dfs(vector<vector<int>> &adj, int node, vector<int> &a, int H){
    if(H+a[node] <= 0) return false;
    if(adj[node].size() == 0) return true;
    for(auto neigh : adj[node]){
        if(dfs(adj,neigh,a,H+a[node])) return true;
    }

    return false;
}


bool isPossible(vector<vector<int>> &adj, vector<int> &a, vector<int> &srcs, int n, int H){

    for(int i=0;i<srcs.size();i++){
        if(dfs(adj,srcs[i],a,H)) return true;
    }


    return false;
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
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        vector<int> srcs;
        vector<int> a(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            indegree[v]++;
            adj[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(indegree[i]==0) srcs.push_back(i);
        }
        int s=0,e=1e9;
        int ans=0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(adj,a,srcs,n,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        if(ans==0) cout<<1<<endl;
        else cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}