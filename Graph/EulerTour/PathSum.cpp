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

void dfs(vector<vector<int>> &adj, int node, int par,
        vector<int> &start, vector<int> &end, vector<int> &val, 
        vector<int> &lt, int &currTime){
            start[node]=currTime;
            lt[currTime]=val[node];
            currTime++;
            for(auto neigh: adj[node]){
                if(neigh==par) continue;
                dfs(adj, neigh, node, start, end, val, lt, currTime);
            }
            end[node]=currTime;
            lt[currTime]=val[node];
            currTime++;
}

void addFT(vector<int> &fenwick, int i, int val){
    while(i<fenwick.size()){
        fenwick[i]+=val;
        i+=i&(-i);
    }
}

int query(vector<int> &fenwick, int i){
    int sum=0;
    while(i>0){
        sum+=fenwick[i];
        i-=i&(-i);
    }
    return sum;
}

signed main() {
    fastio();
    int t=1;
    // cin >> t;
    while (t--) {
        int n, q;
        cin>>n>>q;
        vi a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int> lt(2*n+5), start(n+1), end(n+1), fenwick(2*n+5,0);
        int timer=1;
        dfs(adj, 1, 0, start, end, a, lt, timer);
        for(int i=1;i<=n;i++){
            addFT(fenwick, start[i], a[i]);
            addFT(fenwick, end[i], -a[i]);
        }
        while(q--){
            int typ;
            cin>>typ;
            if(typ==1){
                int node, val;
                cin>>node>>val;
                addFT(fenwick, start[node], val-a[node]);
                addFT(fenwick, end[node], a[node]-val);
                a[node]=val;
            }
            else{
                int node;
                cin>>node;
                int res=query(fenwick, start[node]);
                cout<<res<<endl;
            }
        }
    }
    return 0;
}