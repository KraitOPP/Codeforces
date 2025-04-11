#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

const int MAXN = 1e6;
const int mod = 1e9+7;
long long fac[MAXN + 1];
long long inv[MAXN + 1];

long long exp(long long x, long long n, long long m) {
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}

void inverses(long long p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}

long long choose(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorial(mod);
    inverses(mod);
    int n,r;
    cin>>n>>r;
    cout<<choose(n+r-1,r,mod)<<endl;
    return 0;
}