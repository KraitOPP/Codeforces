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
        int a,b,n,m;
        cin>>a>>b>>n>>m;
        vector<pii> rows, cols;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            rows.pb({x,y});
            cols.pb({y,x});
        }
        sort(all(rows));
        sort(all(cols));
        int vl=0, vh=n-1, hl=0, hr=n-1;
        set<pii> vis;
        int sx=1, sy=1, ex=a, ey=b;
        vector<int> res(2,0);
        for(int i=0;i<m;i++){
            char mov;
            int k;
            cin>>mov>>k;
            if(mov=='D'){
                ex-=k;
                while(vl<=vh && rows[vh].first>ex){
                    if(vis.find(rows[vh])==vis.end()){
                        res[i%2]+=1;
                        vis.insert(rows[vh]);
                    }
                    vh--;
                }
            }
            else if(mov=='U'){
                sx+=k;
                while(vl<=vh && rows[vl].first<sx){
                    if(vis.find(rows[vl])==vis.end()){
                        res[i%2]+=1;
                        vis.insert(rows[vl]);
                    }
                    vl++;
                }
            }
            else if(mov=='L'){
                sy+=k;
                while(hl<=hr && cols[hl].first<sy){
                    if(vis.find({cols[hl].ss, cols[hl].ff})==vis.end()){
                        res[i%2]+=1;
                        vis.insert({cols[hl].ss, cols[hl].ff});
                    }
                    hl++;
                }
            }
            else{
                ey-=k;
                while(hl<=hr && cols[hr].first>ey){
                    if(vis.find({cols[hr].ss, cols[hr].ff})==vis.end()){
                        res[i%2]+=1;
                        vis.insert({cols[hr].ss, cols[hr].ff});
                    }
                    hr--;
                }
            }
        }

        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}