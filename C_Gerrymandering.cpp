#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

int vote(char a, char b, char c){
    int votes=0;
    if(a=='A') votes++;
    if(b=='A') votes++;
    if(c=='A') votes++;

    return votes>=2?1:0;
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
        vector<string> s(2);
        cin>>s[0]>>s[1];
        s[0].insert(0, "G");
        s[1].insert(0, "G");
        vector<vector<int>> dp(n+5,vector<int>(3,-1));
        dp[0][0]=0;
        //0 -- Both are full;
        //1 -- next col 1st row is filled;
        //2 -- next col 2nd row is filled;
        for(int i=0;i<n;i++){
            if(dp[i][0]!=-1){
                if(i+3<=n) dp[i+3][0] = max(dp[i+3][0], dp[i][0]+vote(s[0][i+1],s[0][i+2],s[0][i+3]) + vote(s[1][i+1],s[1][i+2],s[1][i+3]));
                if(i+2<=n) dp[i+1][1] = max(dp[i+1][1], dp[i][0] + vote(s[0][i+1],s[0][i+2],s[1][i+1]));
                if(i+2<=n) dp[i+1][2] = max(dp[i+1][2], dp[i][0] + vote(s[0][i+1],s[1][i+1],s[1][i+2]));
            }
            if(dp[i][1]!=-1){
                if(i+2<=n) dp[i+2][0] = max(dp[i+2][0], dp[i][1]+vote(s[0][i+2],s[1][i+1],s[1][i+2]));
                if(i+4<=n) dp[i+3][1] = max(dp[i+3][1], dp[i][1]+vote(s[0][i+2],s[0][i+3],s[0][i+4]) + vote(s[1][i+1],s[1][i+2],s[1][i+3]));
            }
            if(dp[i][2]!=-1){
                if(i+2<=n) dp[i+2][0] = max(dp[i+2][0], dp[i][2]+vote(s[0][i+1],s[0][i+2],s[1][i+2]));
                if(i+4<=n) dp[i+3][2] = max(dp[i+3][2], dp[i][2]+vote(s[0][i+1],s[0][i+2],s[0][i+3])+vote(s[1][i+2],s[1][i+3],s[1][i+4]));
            }
        
        } 

        cout<<dp[n][0]<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}