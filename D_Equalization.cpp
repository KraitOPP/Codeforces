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
    vector<vector<vector<int>>> dp(63, vector<vector<int>> (63, vector<int>(63,INF)));
    for(int i=0;i<63;i++) dp[i][0][0]=0;
    for(int i=1;i<63;i++){
        for(int x=0;x<63;x++){
            for(int y=0;y<63;y++){
                int cost = 1LL<<i;
                dp[i][x][y]=dp[i-1][x][y];
                if(x-i>=0) dp[i][x][y]=min(dp[i][x][y], cost + dp[i-1][x-i][y]);
                if(y-i>=0) dp[i][x][y]=min(dp[i][x][y], cost + dp[i-1][x][y-i]);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0<<endl;
            continue;
        }
        string s1="",s2="";
        while(x){
            s1+='0'+(x%2);
            x/=2;
        }
        while(y){
            s2+='0'+(y%2);
            y/=2;
        }
        // cout<<s1<<" "<<s2<<endl;
        reverse(all(s1));
        reverse(all(s2));
        int i=0;
        while(i<s1.length() && i<s2.length() && s1[i]==s2[i]){
            i++;
        }
        int common=i;
        // int len1 = s1.length()-i;
        // int len2 = s2.length()-i;
        int res=INF;
        // cout<<dp[62][3][2]<<endl;
        for(int i=0;i<=common;i++){
            if(s1.length()-i>=0 && s2.length()-i>=0) res=min(res, dp[62][s1.length()-i][s2.length()-i]);
        }
        // res=dp[62][s1.length()-common][s2.length()-common];
        int mnlen = min(s1.length(), s2.length()), mxlen = max(s1.length(), s2.length());
        for(int i=min(s1.length(), s2.length());i<63;i++){
            res=min(res, dp[62][mnlen][max(i, mxlen)]);
        }

        cout<<res<<endl;
    }
    return 0;
}