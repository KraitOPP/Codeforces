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

void buildSegTree(vi &a, vi &segTree, int l, int r, int node){
    if(l==r){
        segTree[node]=l;
        return;
    }
    int mid=l+(r-l)/2;
    buildSegTree(a, segTree, l, mid, 2*node);
    buildSegTree(a, segTree, mid+1, r, 2*node+1);

    if(a[segTree[2*node]]<a[segTree[2*node+1]]){
        segTree[node]=segTree[2*node];
    }
    else{
        segTree[node]=segTree[2*node+1];
    }
}

int query(vi &segTree, vi &a, int node, int l, int r, int s, int e){
    if(e<l || s>r) return a.size()-1;
    if(l>=s && r<=e) return segTree[node];
    int mid=l+(r-l)/2;
    int p1=query(segTree, a, 2*node, l, mid, s, e);
    int p2=query(segTree, a, 2*node+1, mid+1, r, s, e);
    if(a[p1]<a[p2]) return p1;
    else return p2;
}

int solve(vi &segTree, vi &a, int n, int l, int r, int height){
    if(l>r) return 0;
    int idx = query(segTree, a, 1, 0, n-1, l, r);
    int mn=a[idx];
    return min(r-l+1, mn-height+solve(segTree, a, n, l, idx-1, mn)+solve(segTree, a, n, idx+1, r, mn));
}

signed main() {
    fastio();
    int n;
    cin>>n;
    vi a(n);
    inp(a,n);
    a.pb(INT_MAX);
    vi segTree(4*n+1);
    buildSegTree(a, segTree, 0, n-1, 1);
    int res=solve(segTree, a, n, 0, n-1, 0);

    cout<<res<<endl;
    return 0;
}