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

int n;
string s;
vector<int> pos;
 
vector<vector<int>> seg;
 
void merge(vector<int>& left, vector<int>& right, vector<int>& curr) {
    int i=0, j=0;
    int lsz=left.size(), rsz=right.size();
    while(i<lsz && j<rsz) {
        if(left[i]<right[j]) {
            curr.push_back(left[i]);
            i++;
        } 
        else{
            curr.push_back(right[j]);
            j++;
        }
    }
    while(i<lsz) {
        curr.push_back(left[i]);
        i++;
    }
    while(j<rsz) {
        curr.push_back(right[j]);
        j++;
    }
}


void build(int idx, int l, int r){
    if(l==r){
        if(s[l-1]=='(' && pos[l] != -1){
            seg[idx].push_back(pos[l]);
        }
        return;
    }
    int mid = l+(r-l)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    merge(seg[2*idx], seg[2*idx+1], seg[idx]);
}
 
int query(int idx, int l, int r, int ql, int qr, int R){
    if(r<ql || l>qr) return 0;
    if(ql<=l && r<=qr) {
        return upper_bound(seg[idx].begin(), seg[idx].end(), R)-seg[idx].begin();
    }
    int mid=l+(r-l)/2;
    return query(2*idx, l, mid, ql, qr, R) + query(2*idx+1, mid+1, r, ql, qr, R);
}
 
signed main() {
    fastio();
    cin>>s;
    n=s.length();
    pos.assign(n+1, -1);
    stack<int> st;
    for (int i=0; i<n; i++){
        if(s[i]=='('){
            st.push(i+1);
        } 
        else{
            if(!st.empty()){
                int leftIdx=st.top();
                st.pop();
                pos[leftIdx]=i+1; 
                pos[i+1]=leftIdx; 
            }
        }
    }
    seg.resize(4*(n+1));
    build(1, 1, n);
 
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        int ans=query(1, 1, n, l, r, r);
        cout<<ans*2<<endl;
    }
 
    return 0;
}
