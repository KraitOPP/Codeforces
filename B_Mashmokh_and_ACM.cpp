#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int MOD = 1e9+7;

int solve(int n, int k, int i, int prv, vector<vector<int>> &dp){
    if(i==k) return 1;
    if(dp[i][prv]!=-1) return dp[i][prv];

    int ans=0;
    for(int j=1;j*prv<=n;j++){
        ans=(ans+solve(n,k,i+1,j*prv,dp))%MOD;
    }

    return dp[i][prv] = ans%MOD;
}

int solveTab(int n, int k){
    vector<vector<int>> dp(k,vector<int>(n+1,-1));
    for(int i)
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n,k;
        cin>>n>>k;
        vector<vector<int>> dp(k,vector<int>(n+1,-1));
        int res=solve(n,k,0,1,dp);
        cout<<res<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}