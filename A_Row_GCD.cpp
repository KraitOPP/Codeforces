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
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    inp(a,n);
    inp(b,m);
    int gc=0;
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        gc=__gcd(gc,a[i]-a[i-1]);
    }
    for(int i=0;i<m;i++){
        cout<<__gcd(gc,b[i]+a[0])<<" ";
    }
    cout<<endl;
    return 0;
}