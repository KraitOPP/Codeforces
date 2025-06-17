#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<
//	pair<int, int>,
//	null_type,
//	less<pair<int, int>>,
//	rb_tree_tag,
//	tree_order_statistics_node_update>
//	ordered_multiset;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define pii pair<int,int>
#define ppii pair<pair<int,int>, int>
#define rep(a,b) for(int i=a;i<=b;i++)
#define vi vector<int>
#define vpii vector<pair<int, int>>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define int long long
const int MAXN = 1e6;
vector<bool> prime;
ll fac[MAXN + 1], inv[MAXN + 1];

ll exp_mod(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
}

void inverses() {
    inv[MAXN] = exp_mod(fac[MAXN], MOD - 2, MOD);
    for (int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

void SieveOfEratosthenes() {
    prime.assign(MAXN + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= MAXN; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MAXN; i += p)
                prime[i] = false;
        }
    }
}

signed main() {
    fastio();
    factorial();
    inverses();
    SieveOfEratosthenes();

    int n;
    cin>>n;
    vector<int> a(2*n);
    inp(a, 2*n);

    map<int, int> mp;
    for (int x : a) mp[x]++;
    vector<pair<int,int>> arr(mp.begin(), mp.end());
    int m=arr.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    dp[0][0]=1;

    for(int i=1; i<=m; i++){
        int num=arr[i-1].first;
        int freq=arr[i-1].second;
        int inv_all=inv[freq];      
        int inv_one=(freq>=1 ? inv[freq-1]:0); 

        for(int j=0; j<=n; j++){
            dp[i][j]=dp[i-1][j]*inv_all % MOD;
            if (prime[num] && j>=1) {
                dp[i][j]=(dp[i][j]+dp[i-1][j-1]*inv_one%MOD)%MOD;
            }
        }
    }

    int res=fac[n]*dp[m][n]%MOD;
    cout<<res<<endl;
    return 0;
}