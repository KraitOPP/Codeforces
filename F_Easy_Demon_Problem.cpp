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

bool checkConditions(int sum1, int sum2, unordered_set<int>& st1, unordered_set<int>& st2, int x, int y, int fsc) {
    if (fsc > 0) {
        int x1 = sum1 - x, x2 = sum2 - y;
        int y1 = sum1 + x, y2 = sum2 + y;
        return (st1.count(x1) && st2.count(x2)) || (st1.count(y1) && st2.count(y2));
    } else {
        int x1 = sum1 - x, x2 = sum2 + y;
        int y1 = sum1 + x, y2 = sum2 - y;
        return (st1.count(x1) && st2.count(x2)) || (st1.count(y1) && st2.count(y2));
    }
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vi a(n), b(m);
    int sum1 = 0, sum2 = 0;
    unordered_set<int> st1, st2;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum1 += a[i];
        st1.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sum2 += b[i];
        st2.insert(b[i]);
    }

    while (q--) {
        int fsc;
        cin >> fsc;

        if (fsc == 0) {
            cout << ((st1.count(sum1) || st2.count(sum2)) ? "YES" : "NO") << endl;
            continue;
        }

        int r = abs(fsc);
        bool flg = false;
        for (int i = 1; i * i <= r; i++) {
            if (r % i != 0) continue;
            int x = i, y = r / i;

            if (checkConditions(sum1, sum2, st1, st2, x, y, fsc) || checkConditions(sum1, sum2, st1, st2, y, x, fsc)) {
                flg = true;
                break;
            }
        }

        cout << (flg ? "YES" : "NO") << endl;
    }

    return 0;
}
