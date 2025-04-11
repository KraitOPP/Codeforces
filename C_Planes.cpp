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
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void dfs(int i, int j, vector<vector<int>> &grid, vector<vi> &vis){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int nwx = i+dx[k],nwy = j+dy[k];
        if(nwx>=0 && nwx<grid.size() && nwy>=0 && nwy<grid[0].size() && grid[nwx][nwy]==0 && !vis[nwx][nwy]){
            dfs(nwx,nwy,grid,vis);
        }
    }
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
        vector<vi> a(n,vi(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        vector<vi> vis(n,vi(n,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && a[i][j]==0){
                    ans++;
                    dfs(i,j,a,vis);
                }
            }
        }
        cout<<ans<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}