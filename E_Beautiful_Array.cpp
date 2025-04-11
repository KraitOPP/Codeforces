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

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        inp(a,n);
        map<int,vector<int>> mp;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(i+1<n && a[i]==a[i+1]){
                i++;
                continue;
            }
            mp[a[i]%k].push_back(a[i]);
        }
        int f=0;
        for(auto itr:mp){
            if(itr.second.size()%2==1){
                f++;
            }
        }
        if(f>1) cout<<-1<<endl;
        else{
            int ans=0;
            for(auto itr :mp){
                sort(itr.second.begin(),itr.second.end());
                vector<int> pre, suff;
                int x=itr.second.size();
                if (x % 2 == 1) {
                    int mndiff=INT_MAX;
                    if(x==1) continue;
                    for(int i=0;i<x-1;i+=2){
                        pre.pb(itr.second[i+1]-itr.second[i]);
                    }
                    for(int i=x-1;i>=1;i-=2){
                        suff.pb(itr.second[i]-itr.second[i-1]);
                    }
                    for(int i=1;i<pre.size();i++) pre[i]+=pre[i-1];
                    for(int i=1;i<suff.size();i++) suff[i]+=suff[i-1];
                    // debug(pre);
                    // debug(suff);
                        // debug(itr.second);
                    for(int i=0;i<x;i++){
                        int diff=0;
                        if(i%2==0){
                            if((i/2-1)>=0) diff+=pre[i/2-1];
                            if(((int)suff.size()-i/2-1)>=0) diff+=suff[(int)suff.size()-i/2-1];
                        }
                        else{
                            if((i/2-1)>=0) diff+=pre[(i/2-1)];
                            // cout<<diff<<" ";
                            if(((int)suff.size()-i/2-2)>=0) diff+=suff[(int)suff.size()-i/2-2];
                            // cout<<diff<<" ";
                            diff+=itr.second[i+1]-itr.second[i-1];
                        }
                        // cout<<i<<" "<<diff<<endl;
                        mndiff=min(mndiff, diff);
                    }
                    ans+=mndiff/k;
                } 
                else{
                    int diff=0;
                    for(int i=0; i<x; i+=2) {
                        diff+=itr.second[i+1]-itr.second[i];
                    }
                    ans+=diff/k;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}