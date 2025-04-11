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

bool isPos(vi &x, vi &t, int n, int mid){
    int xmin=INT_MIN, xmax=INT_MAX;
    for(int i=0;i<n;i++){
        int x_n = x[i]-(mid-t[i]);
        int x_m = x[i]+(mid-t[i]);

        xmin=max(xmin,x_n);
        xmax=min(xmax,x_m);
    }

    return xmin<=xmax;
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
        vi a(n), t(n);
        inp(a,n);
        inp(t,n);
        vi arr;
        for(int i=0;i<n;i++){
            arr.push_back(a[i]+t[i]);
            arr.push_back(a[i]-t[i]);
        }
        int mnx=arr[0],mxx=arr[0];
        for(int i=0;i<arr.size();i++){
            mnx=min(mnx,arr[i]);
            mxx=max(mxx,arr[i]);
        }

        cout<<(mnx+mxx)/2;
        if((mnx+mxx)%2) cout<<".5"<<endl;
        else cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}