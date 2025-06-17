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
vector<int> bdp, wdp;

void dfs(vector<vector<int>> &adj, vector<int> &col, int node, int par){
    for(auto neigh: adj[node]){
        if(neigh==par) continue;
        dfs(adj, col, neigh, node);
    }

    if(col[node]==1){
        //black node
        int res=1;
        for(auto child: adj[node]){
            if(child == par) continue;
            res=(res*(bdp[child]+wdp[child])%MOD)%MOD;
        }

        wdp[node]=0;
        bdp[node]=res;
    }
    else{
        //white node
        vector<int> wvals, bvals;
        for(auto child: adj[node]){
            if(child == par) continue;
            wvals.push_back(wdp[child]);
            bvals.push_back(bdp[child]);
        }
        int n=wvals.size();
        if(n==0){
            wdp[node]=1;
            bdp[node]=0;
            return;
        }
        vector<int> pre(n), suff(n);
        pre[0]=(wvals[0]+bvals[0])%MOD;
        for(int i=1;i<n;i++){
            pre[i]=(pre[i-1]*(wvals[i]+bvals[i])%MOD)%MOD;
        }
        suff[n-1]=(wvals[n-1]+bvals[n-1])%MOD;
        for(int i=n-2;i>=0;i--){
            suff[i]=(suff[i+1]*(wvals[i]+bvals[i])%MOD)%MOD;
        }
        int res=0;
        for(int i=0;i<n;i++){
            int p = (i==0) ? 1 : pre[i-1];
            int s = (i==n-1) ? 1 : suff[i+1];
            res=(res+((p*s)%MOD*bvals[i])%MOD)%MOD;
        }

        wdp[node]=pre[n-1];
        bdp[node]=res%MOD;
    }
}

signed main() {
    fastio();
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    vi a(n);
    inp(a,n);
    bdp.assign(n, 0);
    wdp.assign(n, 0);

    dfs(adj, a, 0, -1);
    cout<<bdp[0]<<endl;

    return 0;
}