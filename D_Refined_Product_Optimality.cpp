#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=998244353;

int modInverse(int A, int M) {
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vi a(n), b(n);
        inp(a,n);
        inp(b,n);
        vi tmpa=a, tmpb=b;
        sort(tmpa.begin(),tmpa.end());
        sort(tmpb.begin(),tmpb.end());
        int res=1;
        for(int i=0;i<n;i++){
            res*=min(tmpa[i], tmpb[i]);
            res%=mod;
        }
        cout<<res<<" ";
        while(q--){
            int o,x;
            cin>>o>>x;
            x--;
            if(o==1){
                int idx = upper_bound(tmpa.begin(), tmpa.end(), a[x]) - tmpa.begin();
                idx--;
                res*=modInverse(min(tmpa[idx], tmpb[idx]), mod);
                res%=mod;
                tmpa[idx]++;
                a[x]++;
                res*=min(tmpa[idx], tmpb[idx]);
                res%=mod;
            }
            else{
                int idx = upper_bound(tmpb.begin(), tmpb.end(), b[x]) - tmpb.begin();
                idx--;
                res*=modInverse(min(tmpa[idx], tmpb[idx]), mod);
                res%=mod;
                tmpb[idx]++;
                b[x]++;
                res*=min(tmpa[idx], tmpb[idx]);
                res%=mod;
            }
            cout<<res<<" ";
        }
        cout<<endl;
    }
    return 0;
}