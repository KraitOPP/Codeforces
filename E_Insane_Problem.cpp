#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        int res = 0;
        int kn = 1;

        while (true) {
            if (kn > r2 / l1) break;

            int min_x = max(l1, (l2 + kn - 1) / kn);
            int max_x = min(r1, r2 / kn);        

            if (min_x <= max_x) {
                res += max_x - min_x + 1;
            }

            if (kn > r2 / k) break;
            kn *= k;
        }

        cout << res << endl;
    }

    return 0;
}
