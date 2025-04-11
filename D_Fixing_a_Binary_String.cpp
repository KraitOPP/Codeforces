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

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vi intervals;
        int curr=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) curr++;
            else{
                intervals.pb(curr);
                curr=1;
            }
        }
        intervals.pb(curr);
        // debug(intervals);
        bool f1=true;
        int res2=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i]!=k){
                f1=false;
            }
            res2+=intervals[i];
        }
        if(f1){
            cout<<res2<<endl;
            continue;
        }
        bool flg=true;
        int res=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i]>k){
                // cout<<"Y "<<i;
                if(intervals[i]>2*k) flg=false;
                else if((i%2!=(intervals.size()-1)%2) && intervals[i]==2*k){
                    for(int j=i+1;j<intervals.size();j++){
                        if(intervals[j]!=k) flg=false;
                    }
                    res+=k;
                    break;
                }
                else if((i%2==(intervals.size()-1)%2) && (intervals[i]+intervals[intervals.size()-1])==2*k ){
                    for(int j=i+1;j<intervals.size()-1;j++){
                        if(intervals[j]!=k) flg=false;
                    }
                    res+=k-intervals[intervals.size()-1];
                    break;
                }
                else flg=false;
            }
            else if(intervals[i]<k){
                // cout<<"Y "<<intervals[i];
                if(i%2!=(intervals.size()-1)%2) flg=false;
                else if( (intervals[i]+intervals[intervals.size()-1])==k ){
                    for(int j=i+1;j<intervals.size()-1;j++){
                        if(intervals[j]!=k) flg=false;
                    }
                    res+=intervals[i];
                    break;
                }
                else flg=false;
            }
            res+=intervals[i];
        }
        if(flg){
            cout<<res<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    } 
    return 0;
}