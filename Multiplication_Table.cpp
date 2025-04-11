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
    int s=1,e=n*n;
    while(s<=e){
        int mid=s+(e-s)/2;
        int sm=0;
        for(int i=1;i<=n;i++) sm+=min(mid/i,n);
        if(sm>=(n*n+1)/2) e=mid-1;
        else s=mid+1;
    }
    
    cout<<s<<endl;
    return 0;
}