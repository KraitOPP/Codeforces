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
    int t;
    cin>>t;
    while(t--){
        int r1,r2,n,m;
        cin>>n>>m>>r1>>r2;
        if(2*max(r1,r2) + 1 > min(n,m)){
            cout<<-1<<endl;
            continue;
        }
        if(2*max(r1,r2) + 1 == min(n,m) && 2*r1+2*r1+3 > max(n,m)){
            cout<<-1<<endl;
            continue;
        }
        else{
            if(r1>r2) swap(r1,r2);
            cout<<(2*(r1+1)) + (2*(r1+1))+(r2+1)+r1+1<<endl;
        }

    }
    return 0;
}