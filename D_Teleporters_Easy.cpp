#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

int solve(int i, int j, map<pair<int,int>,pair<int,int>> &mp, int n, vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==n && j==n) return 0;

    int a1 = INT_MAX;
    if(mp.count({i,j})){
        pair<int,int> dest = mp[{i,j}];
        a1=solve(dest.first,dest.second,mp,n,dp);
    }

    if(i+1 <= n) a1=min(a1,1+solve(i+1,j,mp,n,dp));
    if(j+1 <= n) a1=min(a1,1+solve(i,j+1,mp,n,dp));

    return dp[i][j] = a1;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        auto begin = chrono::high_resolution_clock::now();
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(m,vector<int>(4));
        map<pair<int,int>,pair<int,int>> mp;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<4;j++){
                cin>>a[i][j];
            }
            mp[{a[i][0],a[i][1]}] = {a[i][2],a[i][3]};
        }

        cout<<solve(0,0,mp,n,dp)<<endl;

    return 0;
}