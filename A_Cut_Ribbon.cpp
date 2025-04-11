#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int ans=0;
    for(int i=0;i<=n;i+=a){
        for(int j=0;i+j<=n;j+=b){
            int tmc = n-i-j;
            if(tmc<0) break;
            if(tmc%c==0){
                ans=max(ans,i/a+j/b+tmc/c);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}