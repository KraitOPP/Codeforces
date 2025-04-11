#include<bits/stdc++.h>
 
using namespace std;
 
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
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
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

vector<int> cycle;
bool foundCycle;

bool dfsCycle(vector<vector<int>> &adj, int node, int parent, vector<int> &vis, vector<int> &path) {
    vis[node] = 1;
    path.push_back(node);
    for (auto neigh : adj[node]){
        if(neigh == parent) continue;
        if(vis[neigh]){
            auto it = find(path.begin(), path.end(), neigh);
            if(it != path.end()){
                cycle.assign(it, path.end());
            }
            foundCycle = true;
            return true;
        } 
        else{
            if(dfsCycle(adj, neigh, node, vis, path)){
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

void bfs(vector<vector<int>> &adj, int src, vector<int> &dist) {
    int n = adj.size();
    queue<int> q;
    dist.assign(n, INF);
    dist[src] = 0;     
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto neigh : adj[node]) {
            if (dist[neigh] == INF) { 
                dist[neigh] = dist[node] + 1;
                q.push(neigh);              
            }
        }
    }
}

signed main() {
    fastio();

    int t;
    cin >> t;
    while (t--) {
        int n,a,b;
        cin>>n>>a>>b;
        a--,b--;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        vector<int> vis(n, 0), t1(n,0), t2(n,0);
        vector<int> path;

        foundCycle = false;
        cycle.clear();
        dfsCycle(adj, 0, -1, vis, path);
        bfs(adj, a, t1);
        bfs(adj, b, t2);

        debug(t1);
        debug(t2);

        bool flg=false;
        for(int i=0;i<cycle.size();i++){
            if(t1[cycle[i]]>t2[cycle[i]]) flg=true;
        }
        if(flg) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
