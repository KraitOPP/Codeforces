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

void dfs(vector<vector<int>> &adj, vi &depth, vi &mxdepth, int node, int parent, int d, vi &pre, vi &suff){
    depth[node]=mxdepth[node]=d;
    for(int child: adj[node]){
        if(child==parent) continue;
        dfs(adj, depth, mxdepth, child, node, d+1, pre, suff);
        mxdepth[node]=max(mxdepth[node], mxdepth[child]);
    }
    suff[depth[node]]++;
    pre[mxdepth[node]]++;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }
        vi mxdepth(n), depth(n);
        vi pre(n,0), suff(n,0);
        dfs(adj, depth, mxdepth, 0, -1, 0, pre, suff);
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]+=suff[i+1];
        }
        int res=n-1;
        for(int i=0;i<n;i++){
            int curr=0;
            if(i+1<n) curr+=suff[i+1];
            if(i-1>=0) curr+=pre[i-1];
            res=min(res, curr);
        }

        cout<<res<<endl;
    }
    return 0;
}