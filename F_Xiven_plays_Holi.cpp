#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int mod = 1e9+7;

int solve(int n, vector<int> &dp){
    if(dp[n]!=-1) return dp[n];
    if(n==1) return 0;
    if(n==2) return 1;

    return dp[n] = ((n-1)*(solve(n-1,dp)+solve(n-2,dp)))%mod;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<int> dp(n+1,-1);
        int res = solve(n,dp);
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    
    return 0;
}