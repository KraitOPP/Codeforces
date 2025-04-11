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

int isPos(vi &a, int n, int k, int mid, vi &pre){
    for(int i=0;i<n;i++){
        int prv = a[i]*(i+1)-pre[i];
        int nxtEle = a[i]+mid;
        int up = upper_bound(a.begin(), a.end(), nxtEle)-a.begin();
        int nxt = (pre[n-1]-pre[up-1]) - nxtEle*(n-up);
        int cst = prv+nxt;
        if(cst<=k) return true;
    }
    for(int i=n-1;i>=0;i--){
        int nxt = -a[i]*(n-i-1)+(pre[n-1]-pre[i]);
        int prvEle = a[i]-mid;
        int up = lower_bound(a.begin(), a.end(), prvEle)-a.begin();
        int prv=0;
        if(up>0) prv = prvEle*(up)-pre[up-1];
        int cst = prv+nxt;
        if(cst<=k) return true;
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
    int s=0, e=1e9;
    int res=1e9;
    sort(a.begin(), a.end());
    vi pre(n);
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPos(a,n,k,mid, pre)){
            res=mid;
            e=mid-1;
        }
        else s=mid+1;
    }

    cout<<res<<endl;
    return 0;
}