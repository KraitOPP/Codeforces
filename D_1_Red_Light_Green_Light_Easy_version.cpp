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


void dfs(map<tuple<int,int,int>, tuple<int,int,int>> &adj, tuple<int,int,int> src, map<tuple<int,int,int>, int> &vis){
    if(vis[src]) return;
    vis[src]=1;
    if(adj.count(src)){
        auto neigh=adj[src];
        dfs(adj, neigh, vis);
        if(vis[neigh]==2) vis[src]=2;
\    }
    else{
        vis[src]=2;
    }
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vi pos(n); inp(pos, n);
        vi dl(n); inp(dl, n);

        map<tuple<int,int,int>, tuple<int,int,int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<2;k++){
                    int nxtdir=(j==dl[i])^k;
                    if(nxtdir==0){
                        if(i+1<n){
                            int dist=abs(pos[i+1]-pos[i]);
                            int nwtime=(j+dist)%m;
                            adj[{i, j, k}]={i+1, nwtime, 0};
                        }
                    }
                    else{
                        if(i-1>=0){
                            int dist=abs(pos[i-1]-pos[i]);
                            int nwtime=(j+dist)%m;
                            adj[{i, j, k}]={i-1, nwtime, 1};
                        }
                    }
                }
            }
        }
        map<tuple<int,int,int>, int> vis;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<2;k++){
                    dfs(adj, {i, j, k}, vis);
                }
            }
        }

        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            auto nxtPos = lower_bound(all(pos), x);
            if(nxtPos==pos.end()) cout<<"YES"<<endl;
            else{
                int t=(*nxtPos-x)%m;
                int i=nxtPos-pos.begin();
                if(vis[{i, t, 0}]==2) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }

        }
    }
    return 0;
}