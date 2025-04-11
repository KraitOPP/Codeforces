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
    int n, k;
    cin >> n >> k;
    vi a(n);
    inp(a, n);

    vpii b(n);
    int cnt2 = 0, cnt5 = 0;
    for(int i = 0; i < n; i++){
        int x = a[i], c2 = 0, c5 = 0;
        while (x % 2 == 0){ 
            c2++; 
            x /= 2; 
        }
        while (x % 5 == 0) { 
            c5++; 
            x /= 5; 
        }
        b[i] = {c2, c5};
        cnt2 += c2;
        cnt5 += c5;
    }

    vector<vector<int>> prv(k+1, vector<int>(cnt5+1, INT_MIN));
    prv[1][b[0].ss] = b[0].ff;
    prv[0][0]=0;
    for(int i = 1; i < n; i++){
        vector<vector<int>> curr(k+1, vector<int>(cnt5+1, INT_MIN));
        int c2=b[i].ff, c5=b[i].ss;
        curr[0][0]=0;
        for(int j = 1; j <= k; j++){
            for(int s5 = 0; s5 <= cnt5; s5++){
                curr[j][s5] = prv[j][s5];
                if(s5-c5>=0) curr[j][s5]=max(curr[j][s5], c2+prv[j-1][s5-c5]);
            }
        }
        prv=curr;
    }

    int ans=0;
    for(int s5 = 0; s5 <= cnt5; s5++){
        int s2 = prv[k][s5];
        if(s2>0){
            ans = max(ans, min(s2, s5));
        }
    }
    cout<<ans<<endl;

    return 0;
}
