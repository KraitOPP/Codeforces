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

void buildSegTree(vector<int> &a, vector<int> &seg, int node, int start, int end) {
    if (start==end) {
        seg[node] = a[start];
        return;
    }
    int mid=(start+end)/2;
    buildSegTree(a, seg, 2*node, start, mid);
    buildSegTree(a, seg, 2*node+1, mid+1, end);
    seg[node] = __gcd(seg[2*node], seg[2*node+1]);
}

void update(vector<int> &seg, int node, int start, int end, int idx, int val){
    if (start==end) {
        seg[node] = val;
        return;
    }
    int mid=(start+end)/2;
    if(idx<=mid){
        update(seg, 2*node, start, mid, idx, val);
    }
    else{
        update(seg, 2*node+1, mid+1, end, idx, val);
    }
    seg[node]=__gcd(seg[2*node], seg[2*node+1]);
}

int query(vector<int> &seg, int node, int start, int end, int l, int r, int x) {
    if(r<start || end<l){
        return 0;  
    }
    if(l<=start && end<=r) {
        if(seg[node]%x==0) return 0;
        if(start==end) return 1;
        int mid=(start+end)/2;
        int left=query(seg, 2*node, start, mid, l, r, x);
        if(left>1) return left;
        int right=query(seg, 2*node+1, mid+1, end, l, r, x);
        return left+right;
    }
    int mid=(start+end)/2;
    int left=query(seg, 2*node, start, mid, l, r, x);
    if(left>1) return left;
    int right=query(seg, 2*node+1, mid+1, end, l, r, x);
    return left+right;
}

signed main() {
    fastio();
    int n;
    cin>>n;
    vi a(n);
    inp(a,n);
    int q;
    cin>>q;
    vi gcSeg(4*n);
    buildSegTree(a, gcSeg, 1, 0, n-1);
    while(q--){
        int typ;
        cin>>typ;
        if(typ==2){
            int idx, val;
            cin>>idx>>val;
            idx--;
            a[idx]=val;
            update(gcSeg, 1, 0, n-1, idx, val);
        }
        else{
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            int res = query(gcSeg, 1, 0, n-1, l, r, x);
            if(res>1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            
        }
    }

    return 0;
}