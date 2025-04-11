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
    int l,n,rf,rb;
    freopen("reststops.in","r",stdin);
    cin>>l>>n>>rf>>rb;
    vector<pair<int,int>> a(n);
    vector<int> suff(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    for(int i=n-1;i>=0;i--){
        if(i==n-1) suff[i]=a[i].second;
        else suff[i] = max(a[i].second,suff[i+1]);
    }

    int consumed=0,extraTimeConsumed=0;
    for(int i=0;i<n;i++){
        int extraTime = a[i].first*rf - a[i].first*rb;
        if(suff[i]==a[i].second){
            consumed+=a[i].second*(extraTime - extraTimeConsumed);
            extraTimeConsumed=extraTime;
        }
    }
    freopen("reststops.out","w",stdout);
    cout<<consumed<<endl;

    return 0;
}