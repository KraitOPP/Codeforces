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

int build(vi &seg, vi &arr, int l, int r, int pos){
    if(l==r){
        seg[pos] = arr[l];
        return arr[l];
    }
    int mid = l + (r-l)/2;
    seg[pos] = max(build(seg, arr, l, mid, 2*pos+1), build(seg, arr, mid+1, r, 2*pos+2));
    return seg[pos];
}

int query(vi &seg, int l, int r, int ql, int qr, int pos){
    if(ql<=l && qr>=r) return seg[pos];
    if(ql>r || qr<l) return INT_MIN;
    int mid = l + (r-l)/2;
    return max(query(seg, l, mid, ql, qr, 2*pos+1), query(seg, mid+1, r, ql, qr, 2*pos+2));
}

signed main() {
    fastio();
    int t=1;
    // cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vi a(m);
        inp(a,m);
        int q;
        cin>>q;
        vi seg(4*m);
        build(seg, a, 0, m-1, 0);
        while(q--){
            pii s,e;
            int k;
            cin>>s.ff>>s.ss>>e.ff>>e.ss>>k;
            if(s.ss>e.ss) swap(s,e);
            int l = s.ss, r=e.ss;
            int x = abs(s.ff-e.ff);
            int y = abs(s.ss-e.ss);
            if(x%k==y%k && x%k==0){
                int mx = query(seg, 0, m-1, l-1, r-1, 0);
                int tar = (n-s.ff)%k+1;
                if((n-mx)>=tar) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}