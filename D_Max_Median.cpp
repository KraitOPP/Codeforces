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

bool isPos(vi &a, int n, int mid, int k){
    vi pre(n,0);
    for(int i=0;i<n;i++){
        if(i==0){
            pre[i]=(a[i]>=mid) ? 1:-1;
        }
        else{
            pre[i]=pre[i-1]+((a[i]>=mid) ? 1:-1);
        }
    }
    int mn=0;
    // cout<<mid<<"-> ";
    // for(int i=0;i<n;i++) cout<<pre[i]<<" ";
    // cout<<endl<<endl;
    for(int i=k-1;i<n;i++){
        if(i-k>=0) mn=min(mn, pre[i-k]);
        if((pre[i]-mn) > 0) return true;
    }

    return false;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vi a(n);
    inp(a,n);
    int s=1, e=n, res=0;
    while(s<=e){
        int mid=(e+s)/2;
        if(isPos(a,n,mid,k)){
            res=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    cout<<res<<endl;
    return 0;
}