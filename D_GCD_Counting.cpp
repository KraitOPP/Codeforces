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
const int MAXN = 200000;

pii dfs(vector<vector<int>> &adj, vi &arr, int node, vi &vis, int curr){
    vis[node]=1;
    int res=1;
    int nd=node;
    for(auto neigh: adj[node]){
        if(vis[neigh] || arr[neigh]%curr!=0) continue;
        pii x = dfs(adj, arr, neigh, vis, curr);
        if((x.ff+1)>res){
            res=x.ff+1;
            nd=x.ss;
        }
    }

    return {res, nd};
}


signed main() {
    fastio();
    int n;
    cin>>n;
    vi a(n);
    vector<vi> divis(MAXN+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                if(a[i]/j==j){
                    divis[j].pb(i);
                }
                else{
                    divis[j].pb(i);
                    divis[a[i]/j].pb(i);
                }
            }
        }
    }
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
    int res=0;
    vi arr(MAXN+1,0);
    for(int p=2;p<=MAXN;p++){
        if(arr[p]) continue;
        for(int j=p;j<=MAXN;j+=p){
            arr[j]=1;
        }
        vi vis1(n,0), vis2(n,0);
        for(auto i: divis[p]){
            if(vis1[i] || vis2[i]) continue;
            pii x = dfs(adj, a, i, vis1, p);
            
            pii y = dfs(adj, a, x.ss, vis2, p);
            res=max(res, y.ff);
        }
    }

    cout<<res<<endl;

    return 0;
}