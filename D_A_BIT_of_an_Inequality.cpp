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

int setBitNumber(int n){
    if (n == 0) return -1;
    return 31 - __builtin_clz(n);
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi a(n+1);
        int xr=0;
        vector<vector<vector<int>>> pre(2, vector<vi>(32,vector<int>(n+2,0)));
        for(int i=0; i<32; i++){
            pre[0][i][0]=1; 
            pre[1][i][0]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            xr^=a[i];
            for(int j=0;j<31;j++){
                pre[0][j][i]=pre[0][j][i-1];
                pre[1][j][i]=pre[1][j][i-1];
                if(xr&(1LL<<j)){
                    pre[1][j][i]+=1;
                }
                else{
                    pre[0][j][i]+=1;
                }
            }
        }
        vector<vector<vector<int>>> suff(2, vector<vi>(32,vector<int>(n+2,0)));
        for(int i=n;i>=0;i--){
            for(int j=0;j<31;j++){
                suff[0][j][i]=suff[0][j][i+1];
                suff[1][j][i]=suff[1][j][i+1];
                if(xr&(1LL<<j)){
                    suff[1][j][i]+=1;
                }
                else{
                    suff[0][j][i]+=1;
                }
            }
            xr^=a[i];
        }
        int res=0;
        for(int i=1;i<=n;i++){
            int msb=setBitNumber(a[i]);
            res+=pre[0][msb][i-1]*suff[0][msb][i];
            res+=pre[1][msb][i-1]*suff[1][msb][i];
        }
        cout<<res<<endl;
    }
    return 0;
}