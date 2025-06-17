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

void dfs(vector<vector<int>> &adj, int node, int par, int &leaf){
    if(adj[node].size() == 1 && node != 0) {
        leaf++;
        return;
    }
    for(auto neigh: adj[node]){
        if(neigh == par) continue;
        dfs(adj, neigh, node, leaf);
    }
}

void dfs2(vector<vector<int>> &adj, int node, int par, int &commn, int &lftchain, int &rghtchain){
    vi childs;
    for(auto neigh: adj[node]){
        if(neigh == par) continue;
        childs.push_back(neigh);
    }

    if(childs.size()==2){
        commn=node;
        lftchain=childs[0];
        rghtchain=childs[1];
        return;
    }

    dfs2(adj, childs[0], node, commn, lftchain, rghtchain);
}

int getLen(vector<vector<int>> &adj, int node, int par){
    int res=1;
    for(auto neigh: adj[node]){
        if(neigh == par) continue;
        res+=getLen(adj, neigh, node);
    }

    return res;
}

int power(long long x, unsigned int y, int p) { 
    int res = 1;     
    x = x % p; 
    if (x == 0) return 0;

    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int numleaf=0;
        dfs(adj, 0, -1, numleaf);
        if(numleaf>2){
            cout<<0<<endl;
            continue;
        }
        if(numleaf==1){
            int res=power(2, n, MOD);
            cout<<res<<endl;
        }
        else{
            int cmmn, lft, rght;
            dfs2(adj, 0, -1, cmmn, lft, rght);

            lft=getLen(adj, lft, cmmn);
            rght=getLen(adj, rght, cmmn);
            cmmn=n-(lft+rght);

            int res=power(2, cmmn, MOD);

            int diff=abs(lft-rght);
            int ways;
            if(diff==0){
                ways=2;   
            } 
            else{
                ways=(3*power(2, diff-1, MOD))%MOD;
            }

            res=(res*ways)%MOD;
            cout<<res<<endl;
        }
    }
    return 0;
}