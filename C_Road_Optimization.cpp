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

int solve(vpii &a, int idx, int prv, int k, vector<vector<vector<int>>> &dp){
    if(idx==a.size()-1) return a[prv].ss*(a[idx].ff-a[prv].ff); 
    if(dp[idx][prv][k]!=-1) return dp[idx][prv][k];
    int res = a[prv].ss*(a[idx].ff-a[prv].ff) + solve(a, idx+1, idx, k, dp);
    if(k>0){
        res=min(res, solve(a, idx+1, prv, k-1, dp));
    }

    return dp[idx][prv][k] = res;
}

signed main() {
    fastio();
    int n,l,k;
    cin>>n>>l>>k;
    vpii a(n);
    for(int i=0;i<n;i++) cin>>a[i].ff;
    for(int i=0;i<n;i++) cin>>a[i].ss;
    a.push_back({l, 0});

    vector<vector<int>> dp(n+1, vector<int>(k+1, INF));
    for (int prv=0; prv<n; prv++){
        for (int rem=0; rem<=k; rem++){
            dp[prv][rem]=a[prv].second*(a[n].first-a[prv].first);
        }
    }
    
    for (int idx=n-1; idx>=1; idx--){
        vector<vector<int>> dpprv(n+1, vector<int>(k+1, INF));
        for (int prv=idx-1; prv>=0; prv--){
            for (int rem=0; rem<=k; rem++){
                int costKeep = a[prv].second*(a[idx].first-a[prv].first)+dp[idx][rem];
                int best = costKeep;
                if(rem>0){
                    best = min(best, dp[prv][rem-1]);
                }
                
                dpprv[prv][rem]=best;
            }
        }
        dp=dpprv;
    }
    
    cout << dp[0][k] << "\n";

    return 0;
}