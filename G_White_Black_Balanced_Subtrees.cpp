#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

int dfs(vector<vector<int>> &adj, int node, string s, int &res){
    int bal= s[node-1] == 'B' ?  -1 : 1;
    for(auto neigh: adj[node]){
        bal += dfs(adj,neigh,s,res);
    }
    if(bal==0) res++;
    return bal;
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
        vector<int> a(n);
        string s;
        vector<vector<int>> adj(n+1);
        for(int i=2;i<=n;i++){
            int v;
            cin>>v;
            adj[v].push_back(i);
        }
        cin>>s;
        int res=0;
        dfs(adj,1,s,res);
        
        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}