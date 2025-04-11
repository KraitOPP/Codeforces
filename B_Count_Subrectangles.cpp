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
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n),b(m);
    inp(a,n);
    inp(b,m);
    map<int,int> mp;
    int cnt=0,res=0;
    for(int i=0;i<n;i++){
        if(a[i]==1) cnt++;
        if(a[i]==0 || i==n-1){
            for(int j=1;j<=cnt;j++){
                if(k%j==0) mp[j]+=cnt-j+1;
            }
            cnt=0;
        }
    }
    for(int i=0;i<m;i++){
        if(b[i]==1) cnt++;
        if(b[i]==0 || i==m-1){
            for(int j=1;j<=cnt;j++){
                if(k%j==0) res+=(cnt-j+1)*mp[k/j];
            }
            cnt=0;
        }
    }

    cout<<res<<endl;

    return 0;
}