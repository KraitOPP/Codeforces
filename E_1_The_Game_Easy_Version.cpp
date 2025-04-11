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

vi dp;
vi up;
 
pii combineCandidate(pii &a, pii &b) {
    return (a.first >= b.first ? a : b);
}
 
int merge(int a, int b) {
    if(a>b) return a;
    return b;
}
 
void dfs1(int node, int par, vector<vi> &adj, vi &a) {
    int x=a[node];
    for(auto neigh: adj[node]){
        if(neigh==par) continue;
        dfs1(neigh, node, adj, a);
        x=merge(x, dp[neigh]);
    }
    dp[node]=x;
}
 
void dfs2(int node, int par, vector<vi> &adj, vi &a) {
    vector<int> children;
    for(auto neigh:adj[node]){
        if(neigh==par) continue;
        children.pb(neigh);
    }
    int m=children.size();
    vector<int> prefix(m), suffix(m);
    for (int i=0; i<m; i++){
        int neigh=children[i];
        if(i==0) prefix[i]=dp[neigh];
        else prefix[i]=merge(prefix[i-1], dp[neigh]);
    }
    for (int i=m-1; i>=0; i--){
        int neigh=children[i];
        if(i==m-1) suffix[i]=dp[neigh];
        else suffix[i]=merge(suffix[i+1], dp[neigh]);
    }
 
    for (int i=0; i<m; i++){
        int neigh=children[i];
        vector<int> cand;
        cand.pb(up[node]);
        cand.pb(a[node]);
        if(i>0){
            cand.pb(prefix[i-1]);
        }
        if(i<m-1){
            cand.pb(suffix[i+1]);
        }
        sort(all(cand), [](int &p1, int &p2){
            return p1>p2;
        });

        up[neigh]=cand[0];
 
        dfs2(neigh, node, adj, a);
    }
}
 
signed main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        vector<vi> adj(n);
        for (int i=0; i<n-1; i++){
            int u, v;
            cin>>u>>v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        dp.assign(n, -1);
        up.assign(n, -1);
 
        dfs1(0, -1, adj, a);
        up[0]={-1};
        dfs2(0, -1, adj, a);
        int res = -1;
        for (int i=0; i<n; i++){
            if(up[i] > a[i]){
                if(res==-1 || a[res]<a[i]) res=i;
            }
        }

        cout<<res+1<<endl;
    }
    return 0;
}
