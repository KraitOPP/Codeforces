#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18, mod = 1e9 + 7;
vector<int> p, res, amt;
int ans = 0;

void solve(int curr) {
    int a = p[curr], b = p[p[curr]];
    while (a != b) {
        if (res[a] != -1) {
            while (curr != a) {
                ans += amt[curr];
                res[curr] = 1;
                curr = p[curr];
            }
            return;
        }
        a = p[a];
        b = p[p[b]];
    }

    a = curr;
    while (a != b) {
        b = p[b];
        a = p[a];
    }

    int cycle_start = a;

    int cycle_sum = 0;
    do {
        cycle_sum += amt[a];
        res[a] = 1; 
        a = p[a];
    } while (a != cycle_start);

    int max_cyc = INT_MIN;
    a = cycle_start;
    do {
        max_cyc = max(max_cyc, cycle_sum - amt[a]);
        a = p[a];
    } while (a != cycle_start);

    ans += max_cyc;

    a = curr;
    while (a != cycle_start) {
        ans += amt[a];
        res[a] = 1; 
        a = p[a];
    }
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    p = vector<int>(n + 1);
    amt = vector<int>(n + 1);
    res = vector<int>(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        cin >> amt[i];
    }

    for (int i = 1; i <= n; i++) {
        if (res[i] == -1) {
            solve(i);
        }
    }

    cout << ans << endl;
    return 0;
}
