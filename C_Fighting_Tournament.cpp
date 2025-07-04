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

vector<int> nextGreaterIndex(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

vector<int> prevGreaterIndex(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return res;
}


signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin>>n>>q;
        vi a(n);
        inp(a,n);
        vi pre = prevGreaterIndex(a), suff = nextGreaterIndex(a);
        while(q--){
            int idx,k;
            cin>>idx>>k;
            idx--;
            if(pre[idx]==-1 && suff[idx]==-1){
                if(idx==0 || idx==1) cout<<k<<endl;
                else{
                    int res = max(0LL, k-(idx-1));
                    cout<<res<<endl;
                }
            }
            else if(pre[idx]!=-1){
                cout<<0<<endl;
            }
            else{
                int nxt = suff[idx];
                int res;
                if(idx==0){
                    res=min(k, nxt-1);
                }
                else res = (k<idx) ? 0: min(k-idx+1, nxt-idx);
                cout<<res<<endl;
            }
        }

    }
    return 0;
}
// else if(pre[idx] != -1){
//                 ans = 0;
//             }
//             else {
//                 int nxt = suff[idx]; 
//                 if(idx == 0){
//                     ans = min(k, nxt - 1);
//                 }
//                 else {
//                     ans = (k < idx ? 0 : min(k - idx + 1, nxt - idx));
//                 }
//             }