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
#define MAXN 17

vector<vector<int>> build(vector<int> &parent, int n){
    vector<vector<int>> table(MAXN, vector<int>(n));
    table[0]=parent;

    for(int i=1;i<MAXN;i++){
        for(int j=0;j<n;j++){
            table[i][j]=table[i-1][table[i-1][j]];
        }
    }

    return table;
}

int LCA(vector<vector<int>> &table, vector<int> &level, int a, int b){
    int n=table[0].size();
    if(a==b) return a;
    if(level[a]<level[b]) swap(a,b);
    //level[a]>level[b] -> make a and b on same level
    int msk=level[a]-level[b];
    for(int i=0;i<MAXN;i++){
        int bit = 1<<i;
        if((msk&bit)>0){
            a=table[i][a];
        }
    }
    if(a==b) return a;
    //now both are on same level
    for(int i=MAXN-1;i>=0;i--){
        if(table[i][a]!=table[i][b]){
            a=table[i][a];
            b=table[i][b];
        }
    }
    return table[0][a];
}

void dfs(vector<vector<int>> &adj, vector<int> &parent, vector<int> &levels, int node, int par){
    parent[node]=par;
    for(auto neigh: adj[node]){
        if(neigh==par) continue;
        levels[neigh]=levels[node]+1;
        dfs(adj, parent, levels, neigh, node);
    }
}

signed main() {
    fastio();
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            for(int j=0;j<m;j++){
                int x;
                cin>>x;
                adj[i].pb(x-1);
                adj[x-1].pb(i);
            }
        }

        vector<int> parent(n), levels(n);
        parent[0]=0;
        levels[0]=0;
        dfs(adj, parent, levels, 0, 0);
        vector<vector<int>> table=build(parent, n);
        int q;
        cin>>q;
        cout<<"Case "<<i<<":"<<endl;
        while(q--){
            int a, b;
            cin>>a>>b;
            a--,b--;
            int lca=LCA(table, levels, a, b);
            cout<<lca+1<<endl;
        }

    }
    return 0;
}