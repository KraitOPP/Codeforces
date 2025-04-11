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
        int x,m;
        cin>>x>>m;
        int res=0;
        for(int y=1;y<=min(2*x,m);y++){
            int xr = x^y;
            if(xr==0) continue;
            if(x%xr==0 || y%xr==0) res++;
        }
        cout<<res<<endl;
    }
    return 0;
}