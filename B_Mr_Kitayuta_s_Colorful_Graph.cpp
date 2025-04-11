#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int N=100+20,M=100+20;
vector<int> adj[N][M];
bool vis[N];

void dfs(int node, int c){
    vis[node]=true;
    for(auto neigh:adj[node][c]){
        if(!vis[neigh]){
            dfs(neigh,c);
        }
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--,c--;
        adj[u][c].push_back(v);
        adj[v][c].push_back(u);
    }

    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        u--,v--;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) vis[j]=false;
            dfs(u,i);
            if(vis[v]) cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}