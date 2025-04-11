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


int dfs(vector<vector<int>> &adj, int i, int j, vector<vector<int>> &dp){
    int n=adj.size(), m=adj[0].size();
    if(i==n-1 && j==m-1) return adj[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int res = INT_MAX;
    if(i<n-1) res = min(res, adj[i][j]+dfs(adj, i+1, j, dp));
    if(j<m-1) res = min(res, adj[i][j]+dfs(adj, i, j+1, dp));

    return dp[i][j] = res;
}

int dfs2(vector<vector<int>> &adj, int i, int j, vector<vi> &dp){
    int n=adj.size(), m=adj[0].size();
    if(i==n-1 && j==m-1) return adj[i][j];
    if(dp[i][j]!=-1) return dp[i][j];

    int res = INT_MIN;
    if(i<n-1) res = max(res, adj[i][j]+dfs2(adj, i+1, j, dp));
    if(j<m-1) res = max(res, adj[i][j]+dfs2(adj, i, j+1, dp));

    return dp[i][j] = res;
}

signed main() {
    fastio();
    int t;
    cin>>t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>grid[i][j];
        }
        if((n+m)%2==0){
            cout<<"NO"<<endl;
            continue;
        }
        vector<vector<int>> dp1(n, vector<int> (m,-1));
        vector<vector<int>> dp2(n, vector<int> (m,-1));
        int mn = dfs(grid, 0, 0, dp1);
        int mx = dfs2(grid, 0, 0, dp2);

        // cout<<mn<<" "<<mx<<endl;

        if(mn<=0 && mx>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}