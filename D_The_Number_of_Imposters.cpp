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
#define endl endl
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

pair<int,int> dfs(int node, int prv, vector<int> &color, vector<vector<pair<int,int>>> &adj) {
    color[node]=prv;
    int impCount=(prv==1 ? 1:0); 
    int totalCount=1;
    for(auto &neigh:adj[node]) {
        int nxt=neigh.ff;
        int type=neigh.ss;

        int desired;
        if(prv==1) desired=1-type;
        else desired=type;

        if(color[nxt]==-1) {
            pii res=dfs(nxt, desired, color, adj);
            if(res.first==-1 && res.second==-1)
                return {-1, -1};
            impCount+=res.first;
            totalCount+=res.second;
        } 
        else {
            if(color[nxt]!=desired)
                return {-1, -1}; 
        }
    }
    return {impCount, totalCount};
}

signed main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> adj(n);
        for (int i=0; i<m; i++){
            int u, v;
            string s;
            cin>>u>>v>>s;
            u--; v--; 
            int type=(s=="imposter") ? 1:0;
            adj[u].pb({v, type});
            adj[v].pb({u, type});
        }
        
        vector<int> color(n, -1);
        int ans = 0;
        bool flg = true;
        
        for (int i=0; i<n; i++){
            if(color[i]==-1){
                pii comp=dfs(i, 0, color, adj);
                if(comp.first==-1 && comp.second==-1) {
                    flg=false;
                    break;
                }
                ans+=max(comp.first, comp.second - comp.first);
            }
        }
        
        if(!flg)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
