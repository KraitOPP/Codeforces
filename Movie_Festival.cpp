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
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    int ans=0;
    int currend=0;
    for(int i=0;i<n;i++){
        if(a[i].first>=currend){
            currend=a[i].second;
            ans++;
        }
        else if(currend>=a[i].second){
            currend=a[i].second;
        }
    }

    cout<<ans<<endl;

    return 0;
}