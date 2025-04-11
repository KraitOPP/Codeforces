#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
#define pii pair<int,int>
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("mountains.in","r",stdin);
    int n;
    cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i]={x-y,x+y};
    }
    int res=0;
    sort(a.begin(),a.end(), [&](const pii a, const pii b){
        if(a.first==b.first) return a.second > b.second;
        return a.first<b.first;
    });
    int mx=0;
    for(int i=0;i<n;i++){
        if(a[i].second>mx){
            res++;
            mx=a[i].second;
        }
    }
    freopen("mountains.out","w",stdout);
    cout<<res<<endl;


    return 0;
}