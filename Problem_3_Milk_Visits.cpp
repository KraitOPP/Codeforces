#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(int node, vector<vector<int>> &adj, string type, vector<int> &components, int comp){
    components[node]=comp;
    for(auto neigh: adj[node]){
        if(components[neigh]==-1 && type[neigh] == type[node]){
            dfs(neigh,adj,type,components, comp);
        }
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    string s;
    freopen("milkvisits.in", "r", stdin);
    cin>>n>>m>>s;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> components(n,-1);
    int comp=0;
    for(int i=0;i<n;i++){
        if(components[i]==-1){
            dfs(i,adj,s,components,comp);
        }
        comp++;
    }

    freopen("milkvisits.out", "w", stdout);
    for(int i=0;i<m;i++){
        int src, dest;
        char c;
        cin>>src>>dest>>c;
        src--,dest--;

        if(components[src]==components[dest]){
            if(s[src] == c) cout<<1;
            else cout<<0;
        }
        else cout<<1;
        
    }
    cout<<endl;

    return 0;
}