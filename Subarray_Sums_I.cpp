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
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    int sum=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0) a[i]+=a[i-1];
    }
    mp[0]++;
    int res=0;
    for(int i=0;i<n;i++){

        res+=mp[a[i]-x];
        mp[a[i]]++;
    }

    cout<<res<<endl;
    return 0;
}