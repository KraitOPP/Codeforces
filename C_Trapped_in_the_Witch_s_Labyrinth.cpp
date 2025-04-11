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
map<char,pair<int,int>> mp;
bool dfs(int i, int j, vector<vector<char>> &a, vector<vector<int>> &dp, vector<vi> &vis, int n, int m){
    if(i<0 || i>=n || j>=m || j<0) return false;
    if(dp[i][j]!=-1) return dp[i][j];
    if(vis[i][j]) return dp[i][j]=true;
    vis[i][j]=true;
    if(a[i][j]=='?'){
        bool f1 = dfs(i+1,j,a,dp, vis,n,m);
        bool f2 = dfs(i-1,j,a,dp, vis,n,m);
        bool f3 = dfs(i,j+1,a,dp, vis,n,m);
        bool f4 = dfs(i,j-1,a,dp, vis,n,m);
        return dp[i][j] = (f1 || f2 || f3 || f4);
    }
    
    return dp[i][j] = dfs(mp[a[i][j]].first+i,mp[a[i][j]].second+j,a,dp, vis,n,m);
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    mp['U']={-1,0};mp['D']={1,0};mp['L']={0,-1};mp['R']={0,1};
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,m;
        cin>>n>>m;
        vector<vector<char>> a(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> vis(n,vector<int>(m,0));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    dfs(i,j,a,dp, vis,n,m);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res+=dp[i][j];
            }
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}