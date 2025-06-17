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

void dfs(vector<vector<int>> &adj, int node, int par, vector<int> &start,
                vector<int> &end, vector<int> &lt, vector<int> &val, int &currTime){
                    start[node]=++currTime;
                    lt[currTime]=val[node];
                    for(auto neigh: adj[node]){
                        if(neigh==par) continue;
                        dfs(adj, neigh, node, start, end, lt, val, currTime);
                    }
                    end[node]=currTime;
                }

void buildSegTree(vector<int> &a, vector<int> &segTree, int node, int start, int end){
    if(start==end){
        segTree[node]=(1LL<<a[start]);
        return;
    }
    int mid=start+(end-start)/2;
    buildSegTree(a, segTree, 2*node, start, mid);
    buildSegTree(a, segTree, 2*node+1, mid+1, end);
    segTree[node]=(segTree[2*node]|segTree[2*node+1]);
}

void rangeUpdate(vector<int> &segTree, vector<int> &lazy, int node, int start, int end, int l, int r, int val){
    if(lazy[node]){
        segTree[node]=lazy[node];
        if(start!=end){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>r || end<l) return;
    if(start>=l && end<=r){
        segTree[node]=val;
        lazy[node]=val;
        return;
    }
    int mid=start+(end-start)/2;
    rangeUpdate(segTree, lazy, 2*node, start, mid, l, r, val);
    rangeUpdate(segTree, lazy, 2*node+1, mid+1, end, l, r, val);
    segTree[node]=(segTree[2*node]|segTree[2*node+1]);
}

int queryWithLazy(vector<int> &segTree, vector<int> &lazy, int node, int start, int end, int s, int e){
    if(start>e || end<s) return 0;
    if(lazy[node]){
        segTree[node]=lazy[node];
        if(start!=end){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=s && end<=e) return segTree[node];
    int mid=start+(end-start)/2;
    int left=queryWithLazy(segTree, lazy, 2*node, start, mid, s, e);
    int right=queryWithLazy(segTree, lazy, 2*node+1, mid+1, end, s, e);
    return (left|right);
}

signed main() {
    fastio();
    int t=1;
    // cin >> t
    while (t--) {
        int n,q;
        cin>>n>>q;
        vector<int> color(n+1);
        for(int i=1;i<=n;i++) cin>>color[i];
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        vector<int> lt(n+1), start(n+1), end(n+1);
        int currTime=0;
        dfs(adj, 1, 0, start, end, lt, color, currTime);

        vector<int> segTree(4*n, 0), lazy(4*n, 0);
        buildSegTree(lt, segTree, 1, 1, n);

        while(q--){
            int typ;
            cin>>typ;
            if(typ==1){
                int node, nwCol;
                cin>>node>>nwCol;
                color[node]=nwCol;
                rangeUpdate(segTree, lazy, 1, 1, n, start[node], end[node], (1LL<<nwCol));
            }
            else{
                int node;
                cin>>node;
                int que=queryWithLazy(segTree, lazy, 1, 1, n, start[node], end[node]);
                int res=__builtin_popcountll(que);
                cout<<res<<endl;
            }
        }
    }
    return 0;
}