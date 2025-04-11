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

signed main() {
    fastio();
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n), revadj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u-1].pb({v-1,w});
        revadj[v-1].pb({u-1,w});
    }
    vector<vector<int>> dist(n, vector<int>(2, INF));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    dist[0][0] = 0;
    pq.push({0, 0, 0});

    vector<vector<bool>> vis(n, vector<bool>(2,false));
    while(!pq.empty()){
        int curr = get<0>(pq.top());
        int node = get<1>(pq.top());
        int isRev = get<2>(pq.top());
        pq.pop();
        if(vis[node][isRev]) continue;
        vis[node][isRev]=1;
        if(isRev){
            for(auto itr: revadj[node]){
                int w=itr.second, neigh=itr.first;
                if(!vis[neigh][1] && curr+w<dist[neigh][1]){
                    dist[neigh][1]=curr+w;
                    pq.push({dist[neigh][1], neigh, 1});
                }
            }
        }
        else{
            if(!vis[node][1] && curr < dist[node][1]){
                dist[node][1] = curr;
                pq.push({curr, node, 1});
            }
            for(auto itr: adj[node]){
                int w=itr.second, neigh=itr.first;
                // cout<<neigh<<" "<<curr+w<<endl;
                if(!vis[neigh][0] && curr+w<dist[neigh][0]){
                    dist[neigh][0]=curr+w;
                    pq.push({dist[neigh][0], neigh, 0});
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(dist[i][1]>=INF) cout<<-1<<" ";
        else cout<<dist[i][1]<<" ";
    }
    cout<<endl;

    return 0;
}