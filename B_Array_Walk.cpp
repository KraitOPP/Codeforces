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
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,k,z;
        cin>>n>>k>>z;
        vi a(n), pre(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i==0) pre[i]=a[i];
            else pre[i]=pre[i-1]+a[i];
        }
        int res=a[0];
        for(int i=1;i<n;i++){
            int rem = k-i;
            if(rem<0) break;
            int lftmvs = min(z,rem/2);
            int tmpsum = pre[i];
            tmpsum+=(a[i]+a[i-1])*lftmvs;
            rem-=2*lftmvs;
            if(rem>0 && (z-lftmvs)>0) tmpsum+=a[i-1], rem-=1;
            tmpsum+=pre[i+rem]-pre[i];

            res=max(res,tmpsum);
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}