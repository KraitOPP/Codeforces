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

template <typename T> class SegmentTree {
private:
    vector<T> tree;
    vector<T> arr;
    int n;

    int left(int node) { return 2 * node + 1; }

    int right(int node) { return 2 * node + 2; }

    int mid(int l, int r) { return l + (r - l) / 2; }

    void build(int node, int start, int end){
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int m = mid(start, end);
        build(left(node), start, m);
        build(right(node), m + 1, end);
        tree[node]=tree[left(node)]+tree[right(node)];
    }

    void update(int node, int start, int end, int idx,T val){

        if (start==end) {
            arr[idx] += val;
            tree[node] = (arr[idx]>0) ? 1:0;
            return;
        }
        int m = mid(start, end);
        if (idx <= m)
            update(left(node), start, m, idx, val);
        else
            update(right(node), m + 1, end, idx, val);
        tree[node]=tree[left(node)]+tree[right(node)];
    }

    T query(int node, int start, int end, int l, int r){
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int m = mid(start, end);
        T left_min = query(left(node), start, m, l, r);
        T right_min = query(right(node), m + 1, end, l, r);
        return left_min+right_min;
    }

public:
    SegmentTree(const vector<T>& a)
        :arr(a), n(a.size()){
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int idx, T val){
        update(0, 0, n - 1, idx, val);
    }

    T query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }
};

signed main() {
    fastio();
    int n,q;
    cin>>n>>q;
    vector<int> row(n,0), col(n,0);
    SegmentTree<int> rwseg(row), colseg(col);
    while(q--){
        int typ;
        cin>>typ;
        if(typ==1 || typ==2){
            int x,y;
            cin>>x>>y;
            if(typ==1){
                rwseg.update(x-1, 1);
                colseg.update(y-1, 1);
            }
            else{
                rwseg.update(x-1, -1);
                colseg.update(y-1, -1);
            }
        }
        else{
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            int rowcnt = rwseg.query(x1-1,x2-1);
            int colcnt = colseg.query(y1-1,y2-1);
            if(rowcnt==(x2-x1+1) || colcnt==(y2-y1+1)){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}