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
    vi a(n), suff(n);
    inp(a,n);
    int gc=0;

    suff[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i] = __gcd(a[i],suff[i+1]);
    }
    for(int i=0;i<n-1;i++){
        int tmp = a[i]*suff[i+1];
        tmp/=__gcd(a[i],suff[i+1]);
        gc = __gcd(gc,tmp);

    }
    cout<<gc<<endl;

    return 0;
}