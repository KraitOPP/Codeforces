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
    int a,b;
    cin>>a>>b;
    int x=a*b;
    for(int i=1;i<10;i++){
        int res = ceil((i/10.0)*x);
        cout<<res<<" ";
    }
    return 0;
}