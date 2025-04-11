#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,k;
        cin>>n>>k;
        vector<int> a(n+1),pre(n+1,0),dp(n+3,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=a[i]+pre[i-1];
        }
        for(int i=n;i>=1;i--){
            if(a[i]>k) dp[i]=dp[i+1];
            else{
                int l=i;
                int r=n;
                int idx=i;
                while(l<=r){
                    int mid=(l+r)/2;
                    int currsum=pre[mid]-pre[i-1];
                    if(currsum<=k){
                        idx=mid;
                        l=mid+1;
                    }
                    else r=mid-1;
                }
                dp[i]=(idx-i+1);
                dp[i]+=dp[idx+2];
            }
        }
        int res=0;
        for(int i=1;i<=n;i++) res+=dp[i];
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}