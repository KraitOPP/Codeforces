#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

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
        vector<int> a(n);
        vector<int> dp(n+1);
        for(int i=0;i<n;i++) cin>>a[i];
        dp[n-1]=1;
        dp[n]=0;
        for(int i=n-2;i>=0;i--){
            int ans = 1+dp[i+1];
            if((i+a[i]+1) <= n) ans=min(ans,dp[i+a[i]+1]);
            dp[i]=ans;
        }
        cout<<dp[0]<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}