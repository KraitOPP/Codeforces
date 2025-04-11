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
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<int> a(n),pre(n),suff(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            pre[i]=a[i]+i;
            suff[i]=a[i]-i;
        }
        int x = pre[0];
        for(int i=0;i<n;i++){
            x=max(x,pre[i]);
            pre[i] = x;
        }
        x=suff[n-1];
        for(int i=n-1;i>=0;i--){
            x=max(x,suff[i]);
            suff[i]=x;
        }
        int res=0;
        for(int i=1;i<n-1;i++){
            res=max(res,pre[i-1]+suff[i+1]+a[i]);
        }
        cout<<res<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}