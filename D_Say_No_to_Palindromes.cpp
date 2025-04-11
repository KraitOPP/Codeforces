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

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    string tmp = "abc";
    vector<vector<int>> dp(n+1,vector<int>(6,0));
    int i=0;
    do{
        for(int j=0;j<n;j++){
            dp[j+1][i] = dp[j][i]+(s[j]!=tmp[j%3]); 
        }
        i++;
    } while(next_permutation(tmp.begin(),tmp.end()));
    
    while(m--){
        int l,r;
        cin>>l>>r;
        int res=n;
        for(int i=0;i<6;i++){
            res=min(res,dp[r][i]-dp[l-1][i]);
        }
        cout<<res<<endl;
    }

    return 0;
}