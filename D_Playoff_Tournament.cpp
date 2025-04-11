#include <bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
typedef long long ll;
 
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

int k;
void build(vector<int>& tree, const string &s, int node) {
    if (node >= (1LL << k)) {
        tree[node] = 1;
        return;
    }
    build(tree, s, 2 * node);
    build(tree, s, 2 * node + 1);
    
    char ch = s[node - 1]; 
    if (ch == '0')
        tree[node] = tree[2 * node + 1];
    else if (ch == '1')
        tree[node] = tree[2 * node];
    else 
        tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(vector<int>& tree, string &s, int pos, char newVal) {
    int n = (1LL << k) - 1;
    int posInReversed = (n - 1 - pos);
    s[posInReversed] = newVal;
    
    int node = posInReversed + 1;
    while (node > 0) {
        if (node >= (1LL << k)) {
            tree[node] = 1;
        } 
        else {
            char ch = s[node - 1];
            if (ch == '0')
                tree[node] = tree[2 * node + 1];
            else if (ch == '1')
                tree[node] = tree[2 * node];
            else
                tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
        node /= 2;
    }
}

signed main() {
    fastio();
    cin >> k;
    string s;
    cin >> s;
    

    reverse(s.begin(), s.end());
    
    int treeSize = (1LL << (k + 1));
    vector<int> tree(treeSize, 0);
    
    build(tree, s, 1);
    
    int q;
    cin >> q;
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--; 
        update(tree, s, pos, c);
        cout << tree[1] << "\n"; 
    }
    
    return 0;
}
