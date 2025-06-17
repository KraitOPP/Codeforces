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

void dfs(vector<vi> &adj, int node, int par, vi &mxChild, vi &depth, vi &size, vi &parent){
    parent[node] = par;
    for(auto neigh: adj[node]){
        if(neigh==par) continue;
        depth[neigh]=depth[node]+1;
        dfs(adj, neigh, node, mxChild, depth, size, parent);
        if(size[mxChild[node]]<size[neigh]){
            mxChild[node]=neigh;
        }
        size[node] += size[neigh];
    }
    size[node]++;
}

void dfsHLD(vector<vi> &adj, int node, int par, int currChain, vi &mxChild,
            vi &head, vi &pos, vi &lt, vector<int> &val, int &idx){
                pos[node]=idx;
                lt[idx++]=val[node];
                head[node]=currChain;
                if(mxChild[node]!=0){
                    dfsHLD(adj, mxChild[node], node, currChain, mxChild, head, pos, lt, val, idx);
                }
                for(auto neigh: adj[node]){
                    if(neigh==par || neigh==mxChild[node]) continue;
                    dfsHLD(adj, neigh, node, neigh, mxChild, head, pos, lt, val, idx);
                }
            }

void addSegTree(vector<int> &segTree, int node, int l, int r, int idx, int val){
    if(l==r){
        segTree[node]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(idx<=mid){
        addSegTree(segTree, 2*node, l, mid, idx, val);
    }
    else{
        addSegTree(segTree, 2*node+1, mid+1, r, idx, val);
    }
    segTree[node]=max(segTree[2*node], segTree[2*node+1]);
}

int querySegTree(vector<int> &segTree, int node, int l, int r, int ql, int qr) {
    if(ql>r || qr<l) return INT_MIN;
    if(ql<=l && qr>=r) return segTree[node];
    int mid=l+(r-l)/2;
    return max(querySegTree(segTree, 2*node, l, mid, ql, qr),
               querySegTree(segTree, 2*node+1, mid+1, r, ql, qr));
}

int query(vector<int> &segTree, vector<int> &head, vector<int> &parent, vector<int> &depth, vector<int> &pos, int x, int y) {
    int res=INT_MIN;
    while(head[x]!=head[y]) {
        if(depth[head[x]]<depth[head[y]]) {
            swap(x, y);
        }
        res=max(res, querySegTree(segTree, 1, 1, pos.size()-1, pos[head[x]], pos[x]));
        x=parent[head[x]];
    }

    if(depth[x]<depth[y]) {
        swap(x, y);
    }
    res=max(res, querySegTree(segTree, 1, 1, pos.size()-1, pos[y], pos[x]));

    return res;
}

int main() {
    fastio();
    int t=1;
    // cin >> t;
    while (t--) {
        int n,q;
        cin>>n>>q;
        vi a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<vi> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vi lt(n+1), head(n+1), pos(n+1), size(n+1,0), parent(n+1), depth(n+1,0), mxChild(n+1,0);
        int idx=1;
        dfs(adj, 1, 0, mxChild, depth, size, parent);
        dfsHLD(adj, 1, 0, 1, mxChild, head, pos, lt, a, idx);
        vector<int> segTree(4*n+5, 0);
        for(int i=1;i<=n;i++){
            addSegTree(segTree, 1, 1, n, pos[i], a[i]);
        }
        while(q--){
            int typ;
            cin>>typ;
            if(typ==1){
                int node, val;
                cin>>node>>val;
                lt[pos[node]]=val;
                addSegTree(segTree, 1, 1, n, pos[node], val);
            }
            else{
                int x,y;
                cin>>x>>y;
                cout<<query(segTree, head, parent, depth, pos, x, y)<<" ";
            }
        }
        // cout<<endl;
    }
    return 0;
}