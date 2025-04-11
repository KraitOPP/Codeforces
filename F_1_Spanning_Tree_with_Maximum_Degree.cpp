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

int getPar(vector<int> &par, int x, int y){
    if(par[x] == x) return x;
    return par[x] = getPar(par, par[x], y);
}

bool merge(vector<int> &par, vector<int> &rank, int x, int y){
    x = getPar(par, x, x);
    y = getPar(par, y, y);
    if(x == y) return false;
    if(rank[x] < rank[y]) swap(x, y);
    par[y] = x;
    rank[x]+=rank[y];
    return true;
}

signed main() {
    fastio();
    int t=1;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        vpii edges;
        vector<int> deg(n,0);
        int mxnode=-1, mxdeg=0;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges.pb({u-1,v-1});
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
            deg[u-1]++, deg[v-1]++;
        }
        vector<int> rank(n,1), par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            if(deg[i]>mxdeg){
                mxdeg=deg[i];
                mxnode=i;
            }
        }
        vector<pii> res;
        for(auto neigh: adj[mxnode]){
            res.pb({mxnode+1, neigh+1});
            merge(par, rank, mxnode, neigh);
        }
        for(auto p :edges){
            int u=p.ff, v=p.ss;
            if(merge(par, rank, u, v)){
                res.pb({u+1, v+1});
            }
        }
        for(auto p: res){
            int u=p.ff, v=p.ss;
            cout<<u<<" "<<v<<endl;
        }
        
    }
    return 0;
}