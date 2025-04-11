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
    int t=1;
    // cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        string s;
        cin>>s;
        vi indeg(n,0);
        bool flg=true;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            if(u==v) flg=false;
            adj[u-1].pb(v-1);
            indeg[v-1]++;
        }
        if(!flg){
            cout<<-1<<endl;
            continue;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vi topo;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            topo.pb(top);
            for(auto neigh: adj[top]){
                indeg[neigh]--;
                if(indeg[neigh]==0) q.push(neigh);
            }
        }
        if(topo.size()!=n){
            cout<<-1<<endl;
            continue;
        }
        vector<vector<int>> dp(n, vector<int>(26,0));
        for(int i=0;i<n;i++){
            int node = topo[i];
            dp[node][s[node]-'a']++;
            for(auto neigh: adj[node]){
                for(int j=0;j<26;j++){
                    dp[neigh][j]=max(dp[neigh][j], dp[node][j]);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++) res=max(res, dp[i][j]);
        }

        cout<<res<<endl;
        
    }
    return 0;
}   