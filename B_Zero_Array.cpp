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
    int sum=0;
    int mx=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        mx=max(mx,tmp);
    }

    if(sum%2==1 || sum/2<mx) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;
}