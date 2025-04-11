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

struct TrieNode{
    int left, right;
    int freq=0;
};
int nxtfree;

void insert(vector<TrieNode> &arr, int root, int num){
    int curr=root;
    for(int i=32;i>=0;i--){
        long long x = 1LL<<i;
        if((x&num)>0){
            if(arr[curr].right==-1){
                arr[curr].right=nxtfree;
                nxtfree++;
            }
            curr=arr[curr].right;
            arr[curr].freq++;
        }
        else{
            if(arr[curr].left==-1){
                arr[curr].left=nxtfree;
                nxtfree++;
            }
            curr=arr[curr].left;
            arr[curr].freq++;
        }
    }
}

void remove(vector<TrieNode> &arr, int root, int num){
    int curr=root;
    for(int i=32;i>=0;i--){
        long long x = 1LL<<i;
        if((x&num)>0){
            arr[arr[curr].right].freq--;
            int tmp = arr[curr].right;
            if(arr[arr[curr].right].freq==0){
                arr[curr].right=-1;
            }
            curr=tmp;
        }
        else{
            arr[arr[curr].left].freq--;
            int tmp = arr[curr].left;
            if(arr[arr[curr].left].freq==0){
                arr[curr].left=-1;
            }
            curr=tmp;
        }
    }
}


int query(vector<TrieNode> &arr, int root, int num){
    int curr=root;
    long long res=num;
    for(int i=32;i>=0;i--){
        long long x=1LL<<i;
        if((x&num)>0){
            if(arr[curr].left!=-1 && arr[arr[curr].left].freq!=0){
                curr=arr[curr].left;
            }
            else if(arr[curr].right!=-1 && arr[arr[curr].right].freq!=0){
                res=res^x;
                curr=arr[curr].right;
            }
        }
        else{
            if(arr[curr].right!=-1 && arr[arr[curr].right].freq!=0){
                res=res^x;
                curr=arr[curr].right;
            }
            else if(arr[curr].left!=-1 && arr[arr[curr].left].freq!=0){
                curr=arr[curr].left;
            }
        }
    }

    return res;
}


bool isPos(vector<TrieNode> &arr, vector<int> &a, int n, int mid, int k){
    int root=0;
    for(int i=0;i<mid;i++){
        insert(arr, root, a[i]);
    }
    int res=0;
    for(int i=0;i<mid;i++){
        res=max(res, query(arr, root, a[i]));
    }
    for(int i=mid;i<n;i++){
        remove(arr, root, a[i-mid]);
        insert(arr, root, a[i]);
        res=max(res, query(arr, root, a[i]));
    }
    for(int i=n-1;i>=n-mid;i--){
        remove(arr, root, a[i]);
    }

    return res>=k;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vi a(n);
        inp(a,n);
        int s=1, e=n, res=-1;
        vector<TrieNode> arr(34*n+1);
        for(int i=0;i<=34*n;i++){
            arr[i].left = arr[i].right = -1;
            arr[i].freq=0;
        }
        while(s<=e){
            int mid = s+(e-s)/2;
            nxtfree=1;
            if(isPos(arr, a, n, mid, k)){
                res=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        cout<<res<<endl;
    }
    return 0;
}