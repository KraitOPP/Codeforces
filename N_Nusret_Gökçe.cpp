#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    inp(a,n);
    int res=0;
    for(int i=1;i<n;i++){
        a[i] = max(a[i], a[i-1]-k);
    }
    for(int i=n-2;i>=0;i--){
        a[i] = max(a[i], a[i+1]-k);      
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}