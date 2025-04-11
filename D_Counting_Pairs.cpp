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
        int n,x,y;
        cin>>n>>x>>y;
        vi a(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(),a.end());
        int res=0;
        for(int i=0;i<n;i++){
            int mn = sum-a[i]-y;
            int mx = sum-a[i]-x;
            int mnidx = lower_bound(a.begin()+i+1,a.end(),mn)-a.begin();
            int mxidx = upper_bound(a.begin()+i+1,a.end(),mx)-a.begin()-1;
            res+=mxidx-mnidx+1;
        }

        cout<<res<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   