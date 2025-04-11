#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)
#define mod 1000000007
vector<int> fact(367, 1);
vector<int> invFact(367, 1);

int modInverse(int a, int m) {
    int m0 = m,t,q;
    int x0=0, x1=1;

    if (m==1) return 0;

    while (a>1) {
        q=a/m;
        t=m;

        m=a%m,a=t;
        t=x0;

        x0=x1-q*x0;
        x1=t;
    }

    if (x1<0)
        x1+=m0;

    return x1;
}

void factcalc() {
    for (int i=1; i<=366;i++) {
        fact[i]=(fact[i-1]*i)%mod;
    }
    for (int i=0;i<=366;i++) {
        invFact[i]=modInverse(fact[i], mod);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    factcalc();

    int t;
    cin >> t;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();
        int k, n;
        cin >> k >> n;
        int x = (n-k+1);
        if (x<k) {
            cout<<0<<endl;
        } else {
            int ans=(fact[n-k+1]*invFact[k]%mod)*invFact[n-2*k+1] % mod;
            cout<<ans<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
