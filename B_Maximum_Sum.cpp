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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        vector<int> pre(n+1,0);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            pre[i]=sum;
        }
        int mxsum=0;
        for(int i=0;i<=k;i++){
            mxsum=max(mxsum,pre[n-i]-pre[2*(k-i)]);
        }
        
        cout<<mxsum<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}