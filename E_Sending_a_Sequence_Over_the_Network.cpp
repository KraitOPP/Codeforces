#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i]
#define vi vector<int>

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
        vi a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vi dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(dp[i-1] && (i+a[i]<=n)) dp[i+a[i]]=1;
            if((i-a[i]-1>=0) && dp[i-a[i]-1]) dp[i]=1;
        }

       if(dp[n]) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}