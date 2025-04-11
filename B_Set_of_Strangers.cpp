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
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

// int dfs(vector<vi> &a, int i, int j, vector<vector<int>> &vis){
//     vis[i][j]=1;
//     int res=1;
//     int n=a.size(), m=a[0].size();
//     for(int k=0;k<4;k++){
//         int nwx = i+dx[k];
//         int nwy = j+dy[k];
//         if(nwx<n && nwy<m && nwx>=0 && nwy>=0 && !vis[nwx][nwy] && a[i][j]==a[nwx][nwy]){
//             res+=dfs(a, nwx, nwy, vis);
//         }
//     }

//     return res;
// }

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                st.insert(a[i][j]);
            }
        }
        int res=st.size(), sm=0;
        vector<int> vis(n*m+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[a[i][j]]) continue;
                for(int k=0;k<4;k++){
                    int nwx = i+dx[k];
                    int nwy = j+dy[k];
                    if(nwx>=0 && nwy>=0 && nwx<n && nwy<m && a[nwx][nwy]==a[i][j]){
                        sm++;
                        vis[a[i][j]]=1;
                        break;
                    }
                }
            }
        }
        if(sm==0) res-=1;
        else res=res-1+(sm-1);

        cout<<res<<endl;
    }
    return 0;
}