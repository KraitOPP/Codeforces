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

int lcm(int a, int b){
    return (a*b)/__gcd(a,b);
}

bool isPos(vi &arr, int mid, int k, int a, int x, int b, int y){
    int curr=0;
    int both = mid/lcm(a,b);
    int a1 = mid/a-both, a2=mid/b-both;
    int i=0;
    while(i<both){
        curr+=((x+y)/100.0)*arr[i];
        i++;
    }
    if(x>y){
        while(i<(a1+both)){
            curr+=(x/100.0)*arr[i];
            i++;
        }
        while(i<(a1+both+a2)){
            curr+=(y/100.0)*arr[i];
            i++;
        }
    }
    else{
        while(i<(a2+both)){
            curr+=(y/100.0)*arr[i];
            i++;
        }
        while(i<(a1+both+a2)){
            curr+=(x/100.0)*arr[i];
            i++;
        }
    }

    return curr>=k;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi arr(n);
        inp(arr,n);
        int x,a,y,b,k;
        cin>>x>>a>>y>>b>>k;
        int res=-1;
        sort(arr.begin(), arr.end(), greater<int>());
        int s=1,e=n;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPos(arr,mid,k, a, x, b, y)){
                e=mid-1;
                res=mid;
            }
            else s=mid+1;
        }

        cout<<res<<endl;
    }
    return 0;
}