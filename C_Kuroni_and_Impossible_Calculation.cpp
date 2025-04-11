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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n>m) cout<<0<<endl;
    else{
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) res=(res*abs(a[i]-a[j]))%m;
        }
        cout<<res<<endl;
    }
    return 0;
}