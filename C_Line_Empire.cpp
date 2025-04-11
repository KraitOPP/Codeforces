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
        int n,a,b;
        cin>>n>>a>>b;
        vector<int> pre(n,0), arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i==0) pre[i]=arr[i];
            else pre[i]=pre[i-1]+arr[i];
        }

        int ans=inf;
        for(int i=0;i<n;i++){
            int pos = (a+b)*arr[i]+b*((pre[n-1]-pre[i]) - arr[i]*(n-1-i));
            ans=min(ans,pos);
        }
        ans=min(ans,b*pre[n-1]);
        cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}