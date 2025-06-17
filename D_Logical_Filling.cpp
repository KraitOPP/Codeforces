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

int build(string &s, int n){
    int cnt=0;

    for(int i=0;i<n;i++){
        if(s[i]=='?' && (i==0 || s[i-1]!='o') && (i==n-1 || s[i+1]!='o')){
            s[i]='o';
        } 
        if(s[i]=='o') cnt++;
    }

    return cnt;
}

int buildRev(string &s, int n){
    int cnt=0;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='?' && (i==0 || s[i-1]!='o') && (i==n-1 || s[i+1]!='o')){
            s[i]='o';
        } 
        if(s[i]=='o') cnt++;

    }

    return cnt;
}

signed main() {
    fastio();
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string s1=s, s2=s;
    int c1=build(s1, n);
    int c2=buildRev(s2, n);

    string res=string(n, '?');
    if(c1==k && c2==k){
        for(int i=0;i<n;i++){
            if(s[i]=='.') res[i]='.';
            else if(s[i]=='o') res[i]='o';
            else{
                if(s1[i]==s2[i]) res[i]=s1[i];
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(res[i]=='o') cnt++;
        }
        for(int i=0;i<n;i++){
            if(cnt==k && res[i]=='?') res[i]='.';
            if(i-1>=0 && res[i-1]=='o') res[i]='.';
            if(i+1<n && res[i+1]=='o') res[i]='.';
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(s[i]=='.') res[i]='.';
            else if(s[i]=='o') res[i]='o';
            else if(i-1>=0 && s[i-1]=='o') res[i]='.';
            else if(i+1<n && s[i+1]=='o') res[i]='.';
        }
    }

    cout<<res<<endl;
    return 0;
}