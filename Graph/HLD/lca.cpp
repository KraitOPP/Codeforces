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

void dfs(vector<vector<int>> &adj, int node, int par, vector<int> &parent,
        vector<int> &depth, vector<int> &mxChild, vector<int> &size){
        parent[node]=par;

        //val
        for(auto neigh: adj[node]){
            if(neigh==par) continue;
            depth[neigh] = depth[node]+1;
            dfs(adj, neigh, node, parent, depth, mxChild, size);
            size[node] += size[neigh];
            if(size[mxChild[node]] < size[neigh]) {
                mxChild[node] = neigh;
            }
        }
        size[node]++;
    }

void dfsHLD(vector<vector<int>> &adj, int node, int par, 
            int currChain, vector<int> &mxChild, vector<int> &head){
                head[node] = currChain;
                if(mxChild[node] != 0) {
                    dfsHLD(adj, mxChild[node], node, currChain, mxChild, head);
                }
                for(auto neigh: adj[node]){
                    if(neigh == par || neigh == mxChild[node]) continue;
                    dfsHLD(adj, neigh, node, neigh, mxChild, head);
                }
            }

int LCA(vector<int> &head, vector<int> &depth, vector<int> &parent, int a, int b) {
    while(head[a]!=head[b]){
        if(depth[head[a]]<depth[head[b]]){
            swap(a, b);
        }

        a=parent[head[a]];
    }
    return (depth[a]<depth[b]) ? a:b;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        // vi a(n+1);
        // for(int i=1;i<=n;i++) cin>>a[i];
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=n;i++){
            int m;
            cin>>m;
            for(int j=0;j<m;j++){
                int x;
                cin>>x;
                adj[i].pb(x);
                adj[x].pb(i);
            }
        }
        vector<int> depth(n+1,0), lt(n+1,0), pos(n+1), head(n+1), 
                    parent(n+1), size(n+1,0), mxChild(n+1, 0);

        
        dfs(adj, 1, 0, parent, depth, mxChild, size);
        dfsHLD(adj, 1, 0, 1, mxChild, head);
        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<LCA(head, depth, parent, x, y) << endl;
        }
    }
    return 0;
}