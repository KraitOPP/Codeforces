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
    int mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx =  max(a[i],mx);
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        mn=min(mn,b[i]);
    }


    if(mx>mn) cout<<-1<<endl;
    else{
        int res=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++) res+=m*a[i];
        for(int i=1;i<m;i++) res+=b[i]-a[n-1];
        if(a[n-1]!=b[0]) res+=b[0]-a[n-2];

        cout<<res<<endl;
    }


    return 0;
}