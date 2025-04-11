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

// int findlis(vi a, int n){
//     vi last;
//     vi res(n,1);
//     vi b=a;
//     for (int i=0; i<n; i++) {
//         a[i]=-b[n-1-i];
//     }
//     for(int i=0;i<n;i++){
//         auto it=lower_bound(all(last),a[i]);
//         if(it==last.end()){
//             last.pb(a[i]);
//         }
//         else{
//             *it=a[i];
//         }
//         res[i]=last.size();
//     }
//     reverse(all(res));
//     return res[0];
// }

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi a(n);
        inp(a,n);
        // vi b=a;
        // vi lisa = findlis(a,n, 0);
        int res=n;
        // multiset<pii> st;
        // for(int i=0;i<n;i++){
        //     auto itr = st.upper_bound({a[i], n+1});
        //     // debug(*itr);
        //     if(itr==st.end()){
        //         st.insert({a[i], 1});
        //     }
        //     else{
        //         st.insert({a[i], itr->second+1});
        //         st.erase(itr);
        //     }
        // }
        // int cnt=0;
        // vi tmp;
        // for(auto x: st){
        //     // cout<<x.ff<<" "<<x.ss<<endl;
        //     if(x.ss==1){
        //         cnt++;
        //         tmp.pb(x.ff);
        //     }
        //     else res++;
        // }
        // cout<<cnt<<" "<<res<<endl;
        // debug(st);
        // debug(lisa);
        // debug(lisb);
        // res+=tmp.size()-findlis(tmp, tmp.size());
        int cnt1=0, cnt2=0;
        for(int i=1;i<n;i++){
            if(a[i-1]>=a[i]) cnt1++;
        }
        res=cnt1;
        for(int i=0;i<n;i++){
            res=min(res, (i>0)+cnt1+cnt2);
            if(i-1>=0 && a[i-1]<=a[i]) cnt2++;
            if(i+1>=0 && a[i]>=a[i+1]) cnt1--;
        }
        cout<<res<<endl;
    }
    return 0;
}