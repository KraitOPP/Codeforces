#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int mod = 1e9+7;
vector<vector<int>> dp;

bool isPal(int n){
    string s = to_string(n);
    string s2 = s;
    reverse(s2.begin(),s2.end());

    return s==s2;
}

void solveTab(int n, int m, vector<int> &pal){
    for(int i=0;i<=m;i++) dp[0][i]=1;
    for(int i=0;i<=n;i++) dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i-pal[j]>=0) dp[i][j] = (dp[i][j-1]+dp[i-pal[j]][j])%mod;
            else dp[i][j] = dp[i][j-1]%mod;
        }
    }

    return;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> pal;
    pal.push_back(-1);
    for(int i=1;i<=40000;i++){
        if(isPal(i)) pal.push_back(i);
    }
    dp.resize(40001,vector<int>(pal.size(),0));
    solveTab(40000,pal.size()-1,pal);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        cout<<dp[n][pal.size()-1]<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}