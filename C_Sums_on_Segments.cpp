#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18, mod = 1e9 + 7;

vector<int> sieve(int n) {
    vector<int> spf(n + 1); 
    for (int i = 0; i <= n; i++) spf[i] = i;
    
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {  
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    return spf;
}

int PowerOFPINnfactorial(int n, int p) {
    int ans = 0;
    int temp = p;
    while (temp <= n) {
        ans += n / temp;
        temp = temp * p;
    }
    return ans;
}

void factorize(int x, vector<int>& spf, map<int, int>& factors) {
    while (x != 1) {
        int prime = spf[x];
        factors[prime]++;
        x /= prime;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vi a(n);
    inp(a, n);
    
    vector<int> spf = sieve(m);
    
    map<int, int> prime_power_map;
    for (int i = 2; i <= m; i++) {
        if (spf[i] == i) { 
            prime_power_map[i] = PowerOFPINnfactorial(m, i);
        }
    }

    for (int i = 0; i < n; i++) {
        map<int, int> factors = prime_power_map; 
        
        int x = a[i];
        factorize(x, spf, factors);  
        
        int res = 1;
        for (auto& itr : factors) {
            res = (res * (itr.second + 1)) % mod;  
        }
        cout << res << " ";
    }
    
    return 0;
}
