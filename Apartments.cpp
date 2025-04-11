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
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n),sz(m);
    inp(a,n);
    inp(sz,m);

    sort(a.begin(),a.end());
    sort(sz.begin(),sz.end());
    int i=0,ans=0;
    for(int j=0;j<n;j++){
        while(i<m && sz[i]<(a[j]-k)) i++;
        if(i==m) break;
        if(sz[i]>=(a[j]-k) && sz[i]<=(a[j]+k)){
            ans++;
            i++;
        }
    }

    cout<<ans<<endl;

    return 0;
}