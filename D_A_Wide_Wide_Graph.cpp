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

pii diam(vector<vector<int>> &adj, int node, int par){
    int res=-1, mxnode=node;
    for(auto neigh: adj[node]){
        if(neigh==par) continue;
        pii ch = diam(adj, neigh, node);
        if(ch.ss>res){
            res=ch.ss;
            mxnode=ch.ff;
        }
    }

    return {mxnode, res+1};
}

void dfs(vector<vector<int>> &adj, int node, int par, vi &dist, int curr){
    dist[node]=curr;
    for(auto neigh: adj[node]){
        if(neigh==par) continue;
        dfs(adj, neigh, node, dist, curr+1);
    }
}

signed main() {
    fastio();
    int n;
    cin>>n;
    vector<vi> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
    pii a = diam(adj, 0, -1);
    pii b = diam(adj, a.ff, -1);
    int diameter = b.ss;
    // cout<<diameter<<endl;
    vector<int> dist(n,INT_MAX);
    dfs(adj, a.ff, -1, dist, 0);
    set<int> st;
    // cout<<a.ff<<endl;
    // debug(dist);
    map<int, set<int>> dis;
    for(int i=0;i<n;i++){
        dis[dist[i]].insert(i);
    }
    dfs(adj, b.ff, -1, dist, 0);
    for(int i=0;i<n;i++){
        dis[dist[i]].insert(i);
    }
    // debug(st);
    vector<int> res;
    for(int i=diameter;i<n;i++){
        res.push_back(n);
    }
    // res.pb(n+1-st.size());
    vector<bool> vis(n,false);
    queue<int> q;

    int curr=n+1;
    for(int i=diameter;i>=0;i--){
        for(auto node: dis[i]){
            if(vis[node]) continue;
            q.push(node);
            vis[node]=true;
            curr--;
        }
        res.pb(curr);
    }

    for(int i=n-1;i>=0;i--) cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}