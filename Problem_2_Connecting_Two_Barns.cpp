#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void dfs(vector<vector<int>> &adj, int node, vector<vector<int>> &comps, vector<int> &component, int comp){
    comps[comp].push_back(node);
    component[node]=comp;
    for(int neigh : adj[node]){
        if(component[neigh]!=-1) continue;
        dfs(adj,neigh,comps,component,comp);
    }
}

int cost(int a, int b, vector<vector<int>> &comps) {
	int dist = inf;
	for (int u : comps[a]) {
		int i = lower_bound(comps[b].begin(), comps[b].end(), u) - comps[b].begin();
		if (i > 0){ 
            dist = min(dist, abs(comps[b][i - 1] - u)); 
        }
		if (i < comps[b].size()){ 
            dist = min(dist, abs(comps[b][i] - u)); 
        }
	}

	return (dist==inf) ? dist : dist * dist;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> comps(n+1);
        vector<int> component(n+1,-1);
        int comp=0;
        for(int i=1;i<=n;i++){
            if(component[i]==-1){
                dfs(adj,i,comps,component,comp);
                comp++;
            }
        }
        int ans=cost(component[1],component[n],comps);
        for(int i=0;i<comp;i++){
            ans=min(ans, cost(i,component[1],comps) + cost(i, component[n],comps));
        }

        cout<<ans<<endl;

    }
    return 0;
}