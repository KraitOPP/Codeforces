#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        int mx=0;
        vector<int> cnt(100001,0);
        for(int i=0;i<n;i++){
            int tmp; cin>>tmp;
            cnt[tmp]++;
            mx=max(mx,tmp);
        }
        vector<int> dp(100001,0);
        dp[1] = cnt[1];
        for(int i=2;i<=100000;i++){
            dp[i]=max(cnt[i]*i+dp[i-2],dp[i-1]);
        }
        cout<<dp[mx]<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}