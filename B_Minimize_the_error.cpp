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
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]; 
    for(int i=0;i<n;i++){
        cin>>b[i];
        a[i] = abs(a[i]-b[i]);
    } 
    for(int i=0;i<k1+k2;i++){
        int mx=a[0],idx=0;
        for(int i=0;i<n;i++){
            if(a[i]>mx){
                mx=a[i];
                idx=i;
            }
        }
        a[idx] = abs(a[idx]-1); 
    }

    int res=0;
    for(int i=0;i<n;i++) res+=a[i]*a[i];
    cout<<res<<endl;

    return 0;
}