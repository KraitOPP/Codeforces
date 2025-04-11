#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
int n,m;

void floodTraversal(int i, int j, vector<vector<int>> &a, vector<vector<int>> &vis, vector<vector<vector<pair<int,int>>>> &mp){

    if(i<0 || i>=n || j<0 || j>=n) return;
    if(a[i][j]==0 || vis[i][j]) return;
    vis[i][j]=1;
    for(auto itr: mp[i][j]){
        int x = itr.first,y=itr.second;
        a[x][y]=1;
    }
    for(int k=0;k<4;k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        floodTraversal(nx,ny,a,vis,mp);
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (n,0));
    vector<vector<int>> vis(n,vector<int> (n,0));
    vector<vector<vector<pair<int,int>>>> mp(n,vector<vector<pair<int,int>>> (n));
    for(int i=0;i<m;i++){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        mp[u-1][v-1].push_back({x-1,y-1});
    }

    a[0][0]=1;
    floodTraversal(0,0,a,vis,mp);
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                res++;
            }
        }
    }
    cout<<res<<endl;

    return 0;
}