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

int dfs(int node,vector<vi> &g,vector<int> &vis){
    vis[node]=1;
    int cnt=1;
    for(auto it:g[node]){
        if(!vis[it]){
            return 1+dfs(it,g,vis);
        }
    }
    return 1;
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
        vector<vi> g(n);
        bool flg=false;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            g[x].push_back(y);
            g[y].push_back(x);
            if(x==y || g[x].size()>2 || g[y].size()>2){
                flg=true;
            }
        }

        if(flg){
            cout<<"NO"<<endl;
            continue;
        }

        vi vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,g,vis)%2==1){
                    flg=true;
                    break;
                }
            }
        }
        if(flg) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}