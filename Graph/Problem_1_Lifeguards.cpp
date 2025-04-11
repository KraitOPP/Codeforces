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
    freopen("lifeguards.in", "r", stdin);
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    int left=0,right=0;
    int tot=0;
    for(int i=0;i<n;i++){
        if(a[i].second > right){
            left=max(right,a[i].first);
            tot+=a[i].second-left;
            right=a[i].second;
        }
    }
    
    a.push_back({a[n-1].second,0});
    right = 0;
    int mn=INT_MAX;
    for(int i=0;i<n;i++){
        int res = min(a[i+1].first,a[i].second) - max(right, a[i].first);
        mn=min(mn,res);
        right = max(right,a[i].second);
    }

    freopen("lifeguards.out", "w", stdout);

    cout<<tot-max(0ll,mn)<<endl;

    return 0;
}