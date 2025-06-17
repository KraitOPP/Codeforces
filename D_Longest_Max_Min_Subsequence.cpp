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
        int n;
        cin>>n;
        vi a(n);
        inp(a,n);
        map<int, vector<int>> mp;
        for(int i=n-1;i>=0;i--){
            mp[a[i]].push_back(i);
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto it: mp){
            pq.push({it.second[0], it.first});
        }
        vi res;
        int i=0;
        unordered_map<int,int> vis;
        multiset<pii> mnc, mxc;
        int curridx=0, currStart=0;
        int sz=0;
        while(i<n){
            if(pq.empty()) break;
            pii top = pq.top();
            pq.pop();
            int idx = top.first;
            int val = top.second;
            while(currStart<curridx){
                mnc.erase(mnc.find({-a[currStart], currStart}));
                mxc.erase(mxc.find({a[currStart], currStart}));
                currStart++;
            }
            while(curridx<idx){
                mnc.insert({-a[curridx], curridx});
                mxc.insert({a[curridx], curridx});
                curridx++;
            }
            if(sz%2==1){
                auto it=*mnc.begin();
                res.push_back(it.first);
                mnc.erase(mnc.find(it));
                mxc.erase(mxc.find({-it.first, it.second}));
                i=it.second+1;
                vis[it.first]++;
            }
            else{
                auto it=*mxc.begin();
                res.push_back(it.first);
                mxc.erase(mxc.find(it));
                mnc.erase(mnc.find({-it.first, it.second}));
                i=it.second+1;
                vis[it.first]++;
            }
        }
        cout<<res.size()<<endl;
        for(auto num: res) cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}