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
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    map<pair<int,int>, int> mp;
    int res=0, cnt=0;

    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(b[i]==0) cnt++;
        }
        else{
            pair<int,int> px = {-b[i],a[i]};
            int gcd = __gcd(abs(a[i]),abs(b[i]));
            px.first/=gcd;
            px.second/=gcd;
            if(px.second<0){
                px.first*=-1;
                px.second*=-1;
            }
            else if(px.first==0 && px.second<0){
                px.second*=-1;
            }

            mp[px]++;
            res = max(res,mp[px]);
        }
    }

    cout<<cnt+res<<endl;
    
    return 0;
}