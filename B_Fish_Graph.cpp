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

template <class T, class V> void _print(pair <T, V> par);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T, class V> void _print(pair <T, V> par) {cerr << "{"; _print(par.ff); cerr << ","; _print(par.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define int long long

void DFSCycle(vector<vector<int>> &adj, int node, int par, vector<int> &color, vector<int> &parent, vector<vector<int>> &res){
    if(color[node]==2){
        return;
    }
    if(color[node]==1){
        int cur=par;
        vector<int> cycle;
        cycle.pb(par);
        while (cur!=node){
            cur=parent[cur];
            cycle.pb(cur);
        }
        res.pb(cycle);
        return;
   }
   parent[node]=par;
   color[node]=1;
   for(int v : adj[node]){
        if(v==parent[node]){
            continue;
        }
        DFSCycle(adj, v, node, color, parent, res);
   }
   color[node] = 2;
}

vector<vector<int>> cycles(vector<int> &par, vector<int> &mark, int cycNum){
    vector<vector<int>> cycles(cycNum+1);
    int n=par.size();
    for(int i=0;i<n;i++){

    }
    return cycles;
}


signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> cycles;
        vector<int> par(n, -1), color(n, 0);
        for(int i=0;i<n;i++){
            if(color[i]==0){
                DFSCycle(adj, i, -1, color, par, cycles);
            }
        }
        int cycNode=-1;
        vector<pii> res;
        for(int i=0;i<cycles.size();i++){
            vi curr = cycles[i];
            set<int> vis;
            for(int j=0;j<curr.size();j++){
                vis.insert(curr[j]);
            }
            vector<int> need;
            for(int j=0;j<curr.size();j++){
                int node=curr[j];
                if(adj[node].size()<=2) continue;
                need.clear();
                for(auto neigh: adj[node]){
                    if(vis.count(neigh)) continue;
                    need.pb(neigh);
                    if((int)need.size()>=2) break;
                }
                if(need.size()>=2){
                    cycNode=node;
                    break;
                }
            }
            if(cycNode!=-1){
                for(int j=0;j<curr.size();j++){
                    res.pb({curr[j], curr[(j+1)%curr.size()]});
                }
                res.pb({need[0], cycNode});
                res.pb({need[1], cycNode});
                break;
            }
        }
        if(cycNode!=-1){
            cout<<"YES"<<endl;
            cout<<res.size()<<endl;
            for(auto itr: res){
                cout<<itr.ff+1<<" "<<itr.ss+1<<endl;
            }
        } 
        else cout<<"NO"<<endl;
    }
    return 0;
}