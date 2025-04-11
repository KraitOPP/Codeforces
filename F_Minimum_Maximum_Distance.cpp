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

const int NEG_INF = -1000000000;

void dfs1(const vector<vector<int>> &adj, const vector<bool> &marked, int node, int par,
          vi &dp, vi &best, vi &secbest, vi &bestchild) {
    dp[node] = (marked[node] ? 0 : NEG_INF);
    best[node] = dp[node];
    secbest[node] = NEG_INF;
    bestchild[node] = -1;
    
    for (int neigh : adj[node]) {
        if (neigh == par) continue;
        dfs1(adj, marked, neigh, node, dp, best, secbest, bestchild);
        int candidate = dp[neigh] + 1;
        dp[node] = max(dp[node], candidate);
        if (candidate > best[node]) {
            secbest[node] = best[node];
            best[node] = candidate;
            bestchild[node] = neigh;
        } 
        else if (candidate > secbest[node]) {
            secbest[node] = candidate;
        }
    }
}

void dfs2(const vector<vector<int>> &adj, int node, int par,
          const vi &best, const vi &secbest, const vi &bestchild, vi &dp, int up_val) {
    dp[node] = max(dp[node], up_val);
    for (int neigh : adj[node]) {
        if (neigh == par) continue;
        int candidate = up_val + 1;
        if (neigh == bestchild[node]) {
            candidate = max(candidate, secbest[node] + 1);
        } 
        else {
            candidate = max(candidate, best[node] + 1);
        }
        dfs2(adj, neigh, node, best, secbest, bestchild, dp, candidate);
    }
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<bool> marked(n, false);
        for (int i = 0; i < k; i++) {
            int m;
            cin >> m;
            marked[m - 1] = true;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        vi dp(n, NEG_INF), best(n, NEG_INF), secbest(n, NEG_INF), bestchild(n, -1);
        
        dfs1(adj, marked, 0, -1, dp, best, secbest, bestchild);
        dfs2(adj, 0, -1, best, secbest, bestchild, dp, NEG_INF);
        
        int res = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[i]);
        }
        cout << res << "\n";
    }
    return 0;
}
