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

void dfs(vector<vi> &adj, int node, int par, vi &parent, vi &size,
         vi &depth, vi &mxChild){
            parent[node]=par;
            for(auto neigh: adj[node]){
                if(neigh==par) continue;
                depth[neigh]=depth[node]+1;
                dfs(adj, neigh, node, parent, size, depth, mxChild);
                size[node]+=size[neigh];
                if(size[mxChild[node]]<size[neigh]){
                    mxChild[node]=neigh;
                }
            }
            size[node]++;
         }

void dfsHLD(vector<vi> &adj, int node, int par, int currChain, vi &mxChild,
            vi &head, vi &pos, vi &lt, int &idx){
    pos[node]=idx;
    lt[idx++]=node;
    head[node]=currChain;
    if(mxChild[node]!=0){
        dfsHLD(adj, mxChild[node], node, currChain, mxChild, head, pos, lt, idx);
    }
    for(auto neigh: adj[node]){
        if(neigh==par || neigh==mxChild[node]) continue;
        dfsHLD(adj, neigh, node, neigh, mxChild, head, pos, lt, idx);
    }
}

void updateSegTree(vi &lt, vi &seg, int node, int s, int e, int idx){
    if(s==e){
        if(seg[node]==0){
            seg[node]=lt[s];
        }
        else seg[node]=0;
        return;
    }
    int mid=s+(e-s)/2;
    if(idx<=mid){
        updateSegTree(lt, seg, 2*node, s, mid, idx);
    }
    else{
        updateSegTree(lt, seg, 2*node+1, mid+1, e, idx);
    }

    if(seg[2*node]!=0){
        seg[node]=seg[2*node];
    }
    else seg[node]= seg[2*node+1];
}

int querySegTree(vi &seg, int node, int s, int e, int qs, int qe) {
    if(qs>e || qe<s) return 0;
    if(qs<=s && qe>=e) return seg[node];
    int mid=s+(e-s)/2;
    int p1=querySegTree(seg, 2*node, s, mid, qs, qe);
    if(p1!=0) return p1;
    return querySegTree(seg, 2*node+1, mid+1, e, qs, qe);
}

int query(vi &lt, vi &seg, vi &parent, vi &mxChild, vi &head, vi &pos, int node){
    int res=-1;
    while(head[node]!=head[1]){
        int ans=querySegTree(seg, 1, 1, lt.size()-1, pos[head[node]], pos[node]);
        if(ans!=0){
            res=ans;
        }
        node=parent[head[node]];
    }
    int ans=querySegTree(seg, 1, 1, lt.size()-1, pos[head[node]], pos[node]);
    if(ans!=0){
        res=ans;
    }

    return res;
}

signed main() {
    fastio();
    int t=1;
    // cin >> t;
    while (t--) {
        int n,q;
        cin>>n>>q;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi size(n+1,0), depth(n+1,0), head(n+1,0), pos(n+1,0), lt(n+1)
        , parent(n+1,0), mxChild(n+1,0);
        dfs(adj, 1, 0, parent, size, depth, mxChild);
        int idx=1;
        dfsHLD(adj, 1, 0, 1, mxChild, head, pos, lt, idx);
        vector<int> segTree(4*n+5, 0);
        while(q--){
            int typ, node;
            cin>>typ>>node;
            if(typ==0){
                updateSegTree(lt, segTree, 1, 1, lt.size()-1, pos[node]);
            }
            else{
                cout<<query(lt, segTree, parent, mxChild, head, pos, node)<<endl;
            }
        }

    }
    return 0;
}