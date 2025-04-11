#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].insert(v-1);
        adj[v-1].insert(u-1);
    }
    vector<int> vis(n,0);
    priority_queue<int,vector<int>, greater<int>> pq;
    pq.push(0);
    vis[0]=1;
    while(!pq.empty()){
        int top=pq.top();
        cout<<top+1<<" ";
        pq.pop();
        for(auto neigh: adj[top]){
            if(!vis[neigh]){
                pq.push(neigh);
                vis[neigh]=1;
            }
        }
    }
    cout<<endl;
    return 0;
}