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

class SegmentTree {
    vector<vector<int>> tree;
    string s; 
    int n;

    vector<int> merge(const vector<int>& left, const vector<int>& right) {
        vector<int> result(26, 0);
        for (int i = 0; i < 26; i++) {
            result[i] = left[i] + right[i];
        }
        return result;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = vector<int>(26, 0);
            tree[node][s[start] - 'a'] = 1; 
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    vector<int> query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return vector<int>(26, 0);
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        vector<int> left = query(2 * node + 1, start, mid, l, r);
        vector<int> right = query(2 * node + 2, mid + 1, end, l, r);
        return merge(left, right);
    }

    void update(int node, int start, int end, int idx, char newChar) {
        if (start == end) {
            tree[node] = vector<int>(26, 0);
            tree[node][newChar - 'a'] = 1;
        } 
        else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, newChar);
            } 
            else {
                update(2 * node + 2, mid + 1, end, idx, newChar);
            }
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTree(const string& str) : s(str) {
        n=s.size();
        tree.resize(4*n, vector<int>(26, 0));
        build(0, 0, n-1);
    }

    int queryDistinct(int l, int r) {
        vector<int> freq = query(0, 0, n - 1, l, r);
        int distinctCount = 0;
        for (int count : freq) {
            if (count > 0) distinctCount++;
        }
        return distinctCount;
    }

    void updateChar(int idx, char newChar) {
        update(0, 0, n - 1, idx, newChar);
        s[idx] = newChar; 
    }
};

signed main() {
    fastio();
    string s;
    cin>>s;
    int q;
    cin>>q;
    SegmentTree tree(s);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int pos;
            char c;
            cin>>pos>>c;
            tree.updateChar(pos-1,c);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<tree.queryDistinct(l-1,r-1)<<endl;
        }
    }
    return 0;
}