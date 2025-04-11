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

    seg[node] = min(seg[2*node], seg[2*node+1]);
}

void updateRange(vector<int> &seg, vector<int> &lazy, int node, int start, int end, int l, int r, int val) {
    if(lazy[node]!=0) {
        seg[node]+=lazy[node];
        if(start!=end) {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    
    if(start>r || end<l)
        return;
    
    if(start>=l && end<=r) {
        seg[node]+=val;
        if(start!=end) {
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    
    int mid=(start+end)/2;
    updateRange(seg, lazy, node*2, start, mid, l, r, val);
    updateRange(seg, lazy, node*2+1, mid+1, end, l, r, val);
    seg[node] = min(seg[node*2], seg[node*2+1]);
}

int query(vector<int> &seg, vector<int> &lazy, int node, int start, int end, int l, int r) {
    if(lazy[node]!=0) {
        seg[node]+=lazy[node];
        if(start!=end) {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    
    if(r<start || end<l)
        return INT_MAX; 
    
    if(l<=start && end<=r)
        return seg[node];
    
    int mid=(start+end)/2;
    int left=query(seg, lazy, node*2, start, mid, l, r);
    int right=query(seg, lazy, node*2+1, mid+1, end, l, r);
    return min(left, right);
}


signed main() {
    fastio();
    int n;
    cin>>n;
    vi a(n);
    inp(a,n);
    vi segTree(4*n), lazy(4*n,0);
    buildSegTree(a, segTree, 1, 0, n-1);
    int q;
    cin>>q;
    cin.ignore();
    while(q--){
        string s;

        getline(cin, s);
        stringstream ss(s);
        string word;
        vi op;
        while(ss>>word){
            op.push_back(stoi(word));
        }
        if(op.size()==2){
            int l=op[0], r=op[1];
            if(l<=r){
                cout<<query(segTree, lazy, 1, 0, n-1, l, r)<<endl;
            }
            else{
                cout<<min(query(segTree, lazy, 1, 0, n-1, l, n-1), query(segTree, lazy, 1, 0, n-1, 0, r))<<endl;
            }
        }
        else{
            int l=op[0], r=op[1], val=op[2];
            if(l<=r){
                updateRange(segTree, lazy, 1, 0, n-1, l, r, val);
            }
            else{
                updateRange(segTree, lazy, 1, 0, n-1, l, n-1, val);
                updateRange(segTree, lazy, 1, 0, n-1, 0, r, val);
            }
        }
    }
    return 0;
}