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
    int n;
    cin>>n;
    map<pair<int,int>, int> mp;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        mp[{u,v}]=i;
        mp[{v,u}]=i;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res(n-1,-1);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(adj[i].size()>=3){
            for(int j=0;j<3;j++){
                int u =i;
                int v = adj[i][j];
                res[mp[{u,v}]] = cnt;
                cnt++;
            }
            break;
        }
    }

    for(int i=0;i<n-1;i++){
        if(res[i]==-1){
            res[i]=cnt;
            cnt++;
        }
        cout<<res[i]<<endl;
    }

    return 0;
}