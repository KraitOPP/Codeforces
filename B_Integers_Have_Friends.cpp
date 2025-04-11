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
#define MAXN 200005
#define MAX 30

int lookup[MAXN][MAX]; 

// int buildSegTree(int node, int l, int r, vector<int> &v, vector<int> &tree){
//     if(l==r){
//         tree[node]=v[l];
//         return tree[node];
//     } 
//     int mid = (l+r)/2;
//     int left = buildSegTree(node*2, l, mid, v, tree);
//     int right = buildSegTree(node*2+1, mid+1, r, v, tree);
//     tree[node] = __gcd(left, right);
//     return tree[node];
// }

// int query(int node, int l, int r, int ql, int qr, vector<int> &tree){
//     if(l>qr || r<ql) return 0;
//     if(l>=ql && r<=qr) return tree[node];
//     int mid = (l+r)/2;
//     return __gcd(query(node*2, l, mid, ql, qr, tree), query(node*2+1, mid+1, r, ql, qr, tree));
// }

void buildSparseTable(vector<int> &arr, int n) { 
    for (int i = 0; i < n; i++) 
        lookup[i][0] = arr[i]; 
    for (int j = 1; (1 << j) <= n; j++) { 
        for (int i = 0; (i + (1 << j) - 1) < n; i++) { 
            lookup[i][j] = __gcd(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]); 
        } 
    } 
} 
  
int query(int L, int R) { 
    int j = (int)log2(R - L + 1);  
    return __gcd(lookup[L][j], lookup[R - (1 << j) + 1][j]); 
}

bool isPos(int n, int mid){
    for(int i=mid-1;i<n;i++){
        int res = query(i-mid+1, i);
        if(res>1) return true;
    }
    return false;;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi a(n);
        inp(a,n);
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        vi b(n-1);
        for(int i=1;i<n;i++){
            b[i-1]=abs(a[i]-a[i-1]);
        }
        // vi segTree(4*n);
        // buildSegTree(1, 0, n-2, b, segTree);
        buildSparseTable(b, n-1); 


        int s=1,e=n-1;
        int res=1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPos(n-1, mid)){
                res=mid+1;
                s=mid+1;
            }
            else e=mid-1;
        }
        cout<<res<<endl;
    }
    return 0;
}