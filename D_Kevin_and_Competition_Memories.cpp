#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18, mod = 1e9+7;

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

void _print(int x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
template <typename T, typename V>
void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template <typename T>
void _print(vector<T> v) { cerr << "["; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();
        int n, m;
        cin >> n >> m;
        vi p(n), q(m);
        inp(p, n);
        inp(q, m);
        int myrat = p[0];
        sort(q.begin(), q.end());
        auto itr = upper_bound(q.begin(), q.end(), myrat) - q.begin();
        sort(p.begin(), p.end());
        for (int i = 0; i <= itr - 1; i++) q[i] = 0;
        for (int i = itr; i < m; i++) {
            int idx = lower_bound(p.begin(), p.end(), q[i]) - p.begin();
            q[i] = n-idx;
        }
        sort(q.begin(), q.end());
        for (int i = 1; i <= m; i++) {
            int sum = 0;
            for (int j = i - 1; j < m; j += i) {
                sum += q[j] + 1;
            }
            cout << sum << " ";
        }
        cout << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
