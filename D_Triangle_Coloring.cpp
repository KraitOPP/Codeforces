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
const int MAXN = 1e6;
const int MOD = 998244353;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll choose(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorial();
    inverses();
    int n;
    cin>>n;
    int res=1;
    for(int i=0;i<n/3;i++){
        vi tmp(3);
        for(int i=0;i<3;i++){
            cin>>tmp[i];
        }
        sort(tmp.begin(), tmp.end(), greater<int>());
        if(tmp[0]==tmp[2]){
            res=(res*3)%MOD;
        }
        else if(tmp[1]==tmp[2]){
            res=(res*2)%MOD;
        }
    }
    res*=choose(n/3,n/6);
    res%=MOD;
    cout<<res<<endl;

    return 0;
}