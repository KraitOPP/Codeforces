#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
        cin>>n>>m;
        int mx=-1;
        for(int i=0;i<n;i++){
            int l;
            cin>>l;
            map<int,int> mp;
            for(int i=0;i<l;i++){
                int tmp;
                cin>>tmp;
                mp[tmp]++;
            }
            int cnt=0;
            int mex=0;
            for(int i=0;i<=l+1;i++){
                if(mp.find(i)==mp.end()){
                    mex=i;
                    cnt++;
                    if(cnt==2) break;
                }
            }
            mx=max(mx,mex);
        }
        int ans=(m*(m+1))/2 - (mx*(mx+1))/2;
        if(mx<m){
            ans=ans+mx*(mx+1);
        }
        else{
            ans=(m+1)*mx;
        }
        cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}