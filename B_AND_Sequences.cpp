#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int MAXN = 1e6;
const int MOD = 1e9 + 7;

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
        int n;
        cin>>n;
        vector<int> a(n);
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mn=min(mn,a[i]);
        }
        int cnt=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(a[i]==mn) cnt++;
            if((a[i]&mn)!=mn) flag=false;
        }
        if(flag==false) cout<<0<<endl;
        else{
            int ans=((cnt*(cnt-1)%MOD)*fac[n-2])%MOD;
            cout<<ans%MOD<<endl;
        }
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}