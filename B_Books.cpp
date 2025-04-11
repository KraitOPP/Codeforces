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
    int n,t;
    cin>>n>>t;
    vector<int> a(n);
    inp(a,n);
    int i=0,mx=0;
    int res=0;
    for(int j=0;j<n;j++){
        mx+=a[j];
        while(i<=j && mx>t){
            mx-=a[i];
            i++;
        }

        res=max(res,j-i+1);
    }

    cout<<res<<endl;
    return 0;
}