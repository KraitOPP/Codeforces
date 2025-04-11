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

int getParent(int x, vi &par){
    if(par[x]==x) return x;

    return par[x]=getParent(par[x], par);
}

bool unite(int x, int y, vi &par, vi&size){
    int parx = getParent(x, par);
    int pary = getParent(y, par);

    if(parx==pary) return false;

    if(size[parx]>size[pary]){
        par[pary]=parx;
        size[parx]+=size[pary];
    }
    else{
        par[parx]=pary;
        size[pary]+=size[parx];
    }

    return true;
}

signed main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        vector<vector<int>> edges;
        int candidate=LLONG_MAX;
        
        for(int i=0; i<m; i++){
            int u,v,s;
            cin>>u>>v>>s;
            edges.push_back({s-k, u-1, v-1});
            candidate = min(candidate, abs(s-k));
        }
        
        sort(all(edges));
        
        vector<int> par(n), size(n, 1);
        for (int i=0; i<n; i++) par[i]=i;
        
        int res=0;
        for(int i=0;i<edges.size();i++){
            int diff=edges[i][0]; 
            int u=edges[i][1], v=edges[i][2];
            
            if(unite(u,v,par,size)){
                if(diff>0) res+=diff;
            }
        }

        int ans =(res > 0 ? res : candidate);
        cout<<ans <<endl;
    }
    return 0;
}
