#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
vector<int> d1(2*1e6+10,0), d2(2*1e6+10,0),c(2*1e6+10);

void dfs1(int node, int par, vector<vector<int>> &adj){

    for(auto child: adj[node]){
        if(child!=par){
            dfs1(child,node,adj);
            if(d1[child]+1>d1[node]){
                d2[node]=d1[node];
                d1[node]=d1[child]+1;
                c[node]=child;
            }
            else if(d1[child]+1>d2[node]){
                d2[node]=d1[child]+1;
            }
        }
    }
}

void dfs2(int node, int par, vector<vector<int>> &adj){

    for(auto child: adj[node]){
        if(child!=par){
            if(c[node]==child){
                if(d1[child] < d2[node]+1){
                    d2[child]=d1[child];
                    d1[child]=d2[node]+1;
                    c[child]=node;
                }
                else{
                    d2[child] = max(d2[child], d2[node]+1);
                }
            }
            else{
                d2[child] = d1[child];
                d1[child] = d1[node]+1;
                c[child]=node;
            }
            dfs2(child,node,adj);
        }
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs1(0,-1,adj);
    dfs2(0,-1,adj);

    for(int i=0;i<n;i++) cout<<d1[i]<<" ";
    cout<<endl;


    return 0;
}