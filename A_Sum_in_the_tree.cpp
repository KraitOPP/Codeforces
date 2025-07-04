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

bool dfs(vector<vector<int>> &adj, int node, int par, int curr, vector<int> &s){
    int mn=LLONG_MAX, sum=curr;
    if(s[node]!=-1 && s[node]<curr) return false;
    else if(s[node]!=-1) sum=s[node];

    for(auto neigh: adj[node]){
        if(neigh==par) continue;
        bool x = dfs(adj, neigh, node, sum, s);
        if(!x) return false;
        if(s[node]==-1) mn=min(mn, s[neigh]);
    }
    if(mn==LLONG_MAX) mn=sum;
    if(s[node]==-1){
        s[node]=mn;
    }
    
    return true;
}

int dfs2(vector<vector<int>> &adj, int node, int par, int sum, vector<int> &s){
    int res=s[node]-sum;
    for(auto neigh: adj[node]){
        if(neigh==par) continue;
        res+=dfs2(adj, neigh, node, s[node], s);
    }
    
    return res;
}

signed main() {
    fastio();
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int u; cin>>u;
        adj[u-1].push_back(i);
        adj[i].push_back(u-1);
    }
    vi s(n); inp(s,n);

    bool x=dfs(adj, 0, -1, 0, s);

    if(!x) cout<<-1<<endl;
    else{
        int res=dfs2(adj, 0, -1, 0 ,s);
        
        cout<<res<<endl;
    }

    return 0;
}