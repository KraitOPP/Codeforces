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
    int n;
    cin>>n;
    vi a(n);
    inp(a,n);
    sort(a.begin(),a.end());
    int cost=0;
    for(int i=0;i<n;i++){
        cost+=abs(a[i]-a[n/2]);
    }
    cout<<cost<<endl;
    return 0;
}