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


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int res1=a, res2=b, res3=__gcd(a,b);
        for(int i=1;i<=50;i++){
            int x = pow(a,1/i);
            int y = pow(b,1/i);
            int z = pow(__gcd(a,b),1/i);
            int x1 = pow(x,i);
            int y1 = pow(y,i);
            int z1 = pow(z,i);
            res1=min(res1, i+(x-1)+(a-x1));
            res2=min(res2, i+(y-1)+(b-y1));
            res3=min(res3, i+(z-1)+(__gcd(a,b)-z1));
        }
        // if(a==1) res1++;
        // if(b==1) res2++;
        cout<<res1<<" "<<res2<<" "<<res3<<endl;
        cout<<res1+res2-res3<<endl;
    }
    return 0;
}