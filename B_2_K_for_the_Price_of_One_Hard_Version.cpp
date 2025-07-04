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

bool isPos(vi &a, int n, int mid, int p, int k){
    int cnt=0;
    for(int i=k-1;i<n && cnt<mid;i+=k){
        p-=a[i];
        cnt+=k;
    }

    return p>=0;
}

bool isPos2(vi &a, int n, int mid, int p, int k){
    int cnt=0;
    // cout<<mid<<" - ";
    for(int i=0;i<mid%k;i++){
        cnt++;
        // cout<<a[i]<<" ";
        p-=a[i];
    }
    for(int i=mid%k-1+k;i<n && cnt<mid;i+=k, cnt+=k){
        p-=a[i];
        // cout<<a[i]<<" ";
    }
    // cout<<" "<<p<<endl;

    return p>=0;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n,p,k;
        cin>>n>>p>>k;
        vi a(n);
        inp(a,n);
        sort(a.begin(), a.end());
        int s=0,e=n/k,res=0;
        
        while(s<=e){
            int mid=(s+e)/2;
            if(isPos(a,n,mid*k, p,k)){
                res=mid*k;
                s=mid+1;
            }
            else e=mid-1;
        }
        s=0, e=k;
        int res2=res;
        while(s<=e){
            int mid = s+(e-s)/2;
            if((res+mid)<=n && isPos2(a,n,res+mid, p,k)){
                res2=res+mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        cout<<res2<<endl;
    }
    return 0;
}