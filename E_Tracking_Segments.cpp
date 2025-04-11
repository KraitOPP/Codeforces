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

bool isPos(vpii &a, vi &b, int mid, int m, int n){
    vi tmp(n+1,0), pre(n+1,0);
    for(int i=0;i<mid;i++){
        tmp[b[i]]=1;
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(tmp[i]==1);
    }

    for(int i=0;i<m;i++){
        int x=a[i].first, y=a[i].second;
        int rq = (y-x+1)/2;
        if((pre[y]-pre[x-1])>rq) return true;
    }

    return false;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vpii a(m);
        for(int i=0;i<m;i++) cin>>a[i].first>>a[i].second;
        int q;
        cin>>q;
        vi b(q);
        inp(b,q);

        int s=1, e=q, res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPos(a,b,mid, m, n)){
                res=mid;
                e=mid-1;
            }
            else s=mid+1;
        }

        cout<<res<<endl;
    }
    return 0;
}