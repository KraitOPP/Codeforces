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
    // fastio();
    freopen("hps.in", "r", stdin);
    int n,k;
    cin>>n>>k;
    vector<char> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1,vi(3,0)));
    if(a[0]=='H'){
        dp[0][0][1]=1;
    }
    else if(a[0]=='P') dp[0][0][2]=1;
    else dp[0][0][0]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            //0-hoof, 1-paper, 2-scissor
            dp[i][j][0] = (a[i]=='S')+dp[i-1][j][0];
            dp[i][j][1] = (a[i]=='H')+dp[i-1][j][1];
            dp[i][j][2] = (a[i]=='P')+dp[i-1][j][2];
            if(j>0){
                dp[i][j][0]=max({dp[i][j][0], (a[i]=='S')+max(dp[i-1][j-1][1], dp[i-1][j-1][2])});
                dp[i][j][1]=max({dp[i][j][1], (a[i]=='H')+max(dp[i-1][j-1][0], dp[i-1][j-1][2])});
                dp[i][j][2]=max({dp[i][j][2], (a[i]=='P')+max(dp[i-1][j-1][0], dp[i-1][j-1][1])});
            }
        }
    }
    int res=0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<3;j++) res=max(res, dp[n-1][i][j]);
    }
    freopen("hps.out", "w", stdout);
    cout<<res<<endl;
    return 0;
}