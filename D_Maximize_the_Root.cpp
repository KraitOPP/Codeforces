#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool dfs(vi &a, vector<vector<int>> &adj, int node, int mid){
    if(mid>1e9) return false;
    if(adj[node].size()==0) return a[node]>=mid;

    bool flg=true;
    for(auto child: adj[node]){
        if(a[child]<mid){
            flg&=dfs(a, adj, child,mid-a[child]+mid);
        }
        else flg&=dfs(a, adj, child, mid);
    }

    return flg;
}

bool isPos(vi &a, vector<vector<int>> &adj, int mid){
    return dfs(a, adj, 0, mid);
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
        vi a(n);
        inp(a,n);
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            int v;
            cin>>v;
            adj[v-1].push_back(i);
        }
        int s=0, e=1e9, res=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPos(a, adj, mid)){
                res=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        cout<<res+a[0]<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}