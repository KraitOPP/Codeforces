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
    int  n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> cost(n);
    for(int i=0;i<n;i++) cin>>cost[i];
    vector<vector<int>> dp(n+1,vector<int>(4,inf));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='h'){
            dp[i+1][0] = dp[i][0] + cost[i];
            dp[i+1][1] = min(dp[i][1],dp[i][0]);
            dp[i+1][2] = dp[i][2];
            dp[i+1][3] = dp[i][3];
        }
        else if(s[i]=='a'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1]+cost[i];
            dp[i+1][2] = min(dp[i][2],dp[i][1]);
            dp[i+1][3] = dp[i][3];
        }
        else if(s[i]=='r'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
            dp[i+1][2] = dp[i][2]+cost[i];
            dp[i+1][3] = min(dp[i][3],dp[i][2]);
        }
        else if(s[i]=='d'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
            dp[i+1][2] = dp[i][2];
            dp[i+1][3] = dp[i][3]+cost[i];
        }
        else{
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
            dp[i+1][2] = dp[i][2];
            dp[i+1][3] = dp[i][3];
        }
    }
    cout<<min(dp[n][0],min(dp[n][1],min(dp[n][2],dp[n][3])))<<endl;

    return 0;
}