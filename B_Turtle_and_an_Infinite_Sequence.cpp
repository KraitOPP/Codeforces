#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){ 
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int l = max(0ll,n-m);
        int r = n+m;
        int ans=0;
        for(int i=31;i>=0;i--){
            int tmp = 1<<i;
            int x = l/tmp;
            int y = r/tmp;

            if(x!=y || (x==y && x%2==1)) ans|=tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}