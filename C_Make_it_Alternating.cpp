#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int MOD = 998244353;
const int MAXN = 1e6;
int fac[MAXN + 1];

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorial();

    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        string s;
        cin>>s;
        char prv = '\0';
        int res=1,ans=0,curr=1;
        for(int i=0;i<s.length();i++){
            if(s[i]==prv) curr++;
            else{
                if(curr>=2){
                    res=(res*curr)%MOD;
                    ans+=curr-1;
                }
                curr=1;
            }
            prv=s[i];
        }
        if(curr>=2){
            res=(res*curr)%MOD;
            ans+=curr-1;
        }

        cout<<ans<<" "<<(res*fac[ans])%MOD<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}