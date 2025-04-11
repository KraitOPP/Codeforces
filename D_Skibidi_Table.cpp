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
    while(t--){
        int n, q;
        cin>>n>>q;
        while(q--){
            string typ;
            cin>>typ;
            if(typ=="->"){
                int x, y;
                cin>>x>>y;
                x--,y--;
                int res=0;
                for(int i=n-1; i>=0; i--){
                    int nx=(x/(long long)pow(2LL,i))%2;
                    int ny=(y/(long long)pow(2LL,i))%2;
                    int rem;
                    if(nx==0 && ny==0){
                        res=res*4;
                    }
                    else if(nx==1 && ny==1){
                        res=res*4+1;
                    }
                    else if(nx==1 && ny==0){
                        res=res*4+2;
                    }
                    else{
                        res=res*4+3;
                    }
                }
                cout<<(res+1)<<endl;

            } 
            else{
                int d;
                cin>>d;
                d--; 
                int x=0, y=0;
                for(int i=n-1; i>=0; i--) {
                    int rem=(d/(long long)pow(2LL, 2*i))%4;
                    int nx, ny;
                    if(rem==0){ 
                        nx=0; 
                        ny=0; 
                    }
                    else if(rem==1){
                        nx=1; 
                        ny=1; 
                    }
                    else if(rem==2){ 
                        nx=1;
                        ny=0;
                    }
                    else{
                        nx=0;
                        ny=1;
                    }
                    x=x*2+nx;
                    y=y*2+ny;
                }
                cout<<x+1<<" "<<y+1<<endl;
            }
        }
    }

    return 0;
}