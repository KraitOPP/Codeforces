#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;


bool isCyclicUtil(int node, vector<set<int>> &adj, vector<int> &vis, int parent) {
    vis[node] = true;

    for (int i : adj[node]) {
        if (!vis[i]) {
            if (isCyclicUtil(i, adj, vis, node))
                return true;
        }
        else if (i != parent)
            return true;
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
        int n;
        cin>>n;
        vector<int> a(n);
        vector<set<int>> adj(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
            adj[i].insert(a[i]);
            adj[a[i]].insert(i);
        }

        int comp=0;
        int cyclic=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCyclicUtil(i, adj, vis, -1)){
                    cyclic++;
                }
                comp++;
            }
        }

        int mn = cyclic + ((comp-cyclic)>0 ? 1 : 0);
        int mx=comp;

        cout<<mn<<" "<<mx<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}