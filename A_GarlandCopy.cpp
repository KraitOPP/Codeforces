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
    
    int n;
    cin >> n;
    vi a(n);
    set<int> st;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]!=0) st.insert(a[i]);
    }

    if (st.empty()) {
        cout << (n == 1 ? 0 : 1) << endl;
        return 0;
    }

    int cnt0 = 0, cnt1 = 0, res = 0;

    for (int i = 1; i <= n; i++) {
        if (st.find(i) == st.end()) {
            (i % 2 == 0) ? cnt0++ : cnt1++;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i] != 0 && a[i - 1] != 0 && (a[i] % 2 != a[i - 1] % 2)) {
            res++;
        }
    }
    int start = -1, end = -1;
    vector<int> eve, odd, evodd, evespecial, oddspecial;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (start == -1) start = i;
            end = i;
        }

        if (a[i] != 0 || i == n - 1) {
            if (start == -1) continue;

            if (start == 0) {
                (a[i] % 2 == 0) ? evespecial.pb(end - start + 1) : oddspecial.pb(end - start + 1);
            } else if (end == n - 1) {
                (a[start - 1] % 2 == 0) ? evespecial.pb(end - start + 1) : oddspecial.pb(end - start + 1);
            } else {
                if (a[start - 1] % 2 == 0 && a[i] % 2 == 0) eve.pb(end - start + 1);
                else if (a[start - 1] % 2 == 1 && a[i] % 2 == 1) odd.pb(end - start + 1);
                else evodd.pb(end - start + 1);
            }
            start = end = -1;
        }
    }


    sort(all(eve), greater<int>());
    sort(all(odd), greater<int>());
    sort(all(evodd));

    debug(cnt0);
    debug(cnt1);
    debug(eve);
    debug(odd);
    debug(evodd);
    debug(evespecial);
    debug(oddspecial);

    while (!odd.empty() && odd.back() <= cnt1) {
        cnt1 -= odd.back();
        odd.pop_back();
    }
    if (!odd.empty() && odd.back() > cnt1) {
        odd.back() -= cnt1;
        cnt1 = 0;
    }

    while (!oddspecial.empty() && oddspecial.back() <= cnt1) {
        cnt1 -= oddspecial.back();
        oddspecial.pop_back();
    }

    if (!oddspecial.empty() && oddspecial.back() > cnt1) {
        oddspecial.back() -= cnt1;
        cnt1 = 0;
    }

    while (!eve.empty() && eve.back() <= cnt0) {
        cnt0 -= eve.back();
        eve.pop_back();
    }
    if (!eve.empty() && eve.back() > cnt0) {
        eve.back() -= cnt0;
        cnt0 = 0;
    }
    
    while (!evespecial.empty() && evespecial.back() <= cnt0) {
        cnt0 -= evespecial.back();
        evespecial.pop_back();
    }

    if (!evespecial.empty() && evespecial.back() > cnt0) {
        evespecial.back() -= cnt0;
        cnt0 = 0;
    }

    if (cnt0 > 0) {
        while (!evodd.empty() && evodd.back() <= cnt0) {
            cnt0 -= evodd.back();
            evodd.pop_back();
            res++;
        }
        if (!evodd.empty() && evodd.back() > cnt0) {
            evodd.back() -= cnt0;
            cnt0 = 0;
        }

        while (!oddspecial.empty() && oddspecial.back() <= cnt0) {
            cnt0 -= oddspecial.back();
            oddspecial.pop_back();
            res++;
        }

        if (!oddspecial.empty() && oddspecial.back() > cnt1) {
            oddspecial.back() -= cnt0;
            res++;
            cnt0 = 0;
        }

        while (!odd.empty() && odd.back() <= cnt0) {
            cnt0 -= odd.back();
            odd.pop_back();
            res += 2;
        }
        if (!odd.empty() && odd.back() > cnt0) {
            odd.back() -= cnt0;
            cnt0 = 0;
        }
    }

    if (cnt1 > 0) {
        while (!evodd.empty() && evodd.back() <= cnt1) {
            cnt1 -= evodd.back();
            evodd.pop_back();
            res++;
        }
        if (!evodd.empty() && evodd.back() > cnt1) {
            evodd.back() -= cnt1;
            cnt1 = 0;
        }

         while (!evespecial.empty() && evespecial.back() <= cnt1) {
            cnt1 -= evespecial.back();
            evespecial.pop_back();
            res++;
        }

        if (!evespecial.empty() && evespecial.back() > cnt1) {
            evespecial.back() -= cnt1;
            cnt1 = 0;
            res++;
        }

        while (!eve.empty() && eve.back() <= cnt1) {
            cnt1 -= eve.back();
            eve.pop_back();
            res += 2;
        }
        if (!eve.empty() && eve.back() > cnt1) {
            eve.back() -= cnt1;
            cnt1 = 0;
        }
    }

    cout << res << endl;

    return 0;
}
