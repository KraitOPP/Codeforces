#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<
//    pair<int, int>,
//    null_type,
//    less<pair<int, int>>,
//    rb_tree_tag,
//    tree_order_statistics_node_update>
//    ordered_multiset;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
#define inp(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define pii pair<int, int>
#define ppii pair<pair<int, int>, int>
#define rep(a, b) for (int i = a; i <= b; i++)
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
 
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
 
template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T> void _print(unordered_set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T, class V> void _print(unordered_map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T> void _print(unordered_multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(unordered_set<T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(unordered_multiset<T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T, class V> void _print(unordered_map<T, V> v) {
    cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]";
}
 
#define int long long
const int MAXN = 2e5+10;
vector<bool> prime(MAXN, true);
vector<int> spf(MAXN, 1);
 
void SieveOfEratosthenes() {
    for (int p = 2; p * p <= MAXN; p++) {
        for (int i = p * p; i < MAXN; i += p)
            prime[i] = false;
    }
}
 
void sieve() {
    spf[0] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (spf[i] == 1) {
            for (int j = i; j < MAXN; j += i) {
                if (spf[j] == 1)
                    spf[j] = i;
            }
        }
    }
}
 
signed main() {
    fastio();
    SieveOfEratosthenes();
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        inp(a, n);
        sort(all(a));
        int cntprimes = 0, res = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
            if (prime[a[i]]) {
                cntprimes++;
                res+=(cntprimes - mp[a[i]]);
            }
            else {
                int x = spf[a[i]];
                int y = a[i] / x;
                if (prime[x] && prime[y]) {
                    if(x==y){
                        res+=mp[x]+(mp[a[i]]);
                    }
                    else{
                        res += mp[x] + mp[y]+ (mp[a[i]]);
                    }
                }
            }
        }
        // for(auto it: mp){
        //     res+=(cntprimes-it.ss)*it.ss;
        // }
        // cout << res <<" "<<cntprimes<<endl; 
        cout << res << endl;  
    }
    return 0;
}
