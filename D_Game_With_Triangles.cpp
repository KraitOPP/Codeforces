#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < m; j++)
            cin >> b[j];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int kmax = min({ (n + m) / 3, n, m });
        int Amax = n / 2;
        vector<ll> fA(Amax + 1, 0);
        for (int x = 1; x <= Amax; x++)
            fA[x] = fA[x - 1] + (a[n - x] - a[x - 1]);
        int Bmax = m / 2;
        vector<ll> fB(Bmax + 1, 0);
        for (int y = 1; y <= Bmax; y++)
            fB[y] = fB[y - 1] + (b[m - y] - b[y - 1]);
        cout << kmax << "\n";
        if(kmax == 0)
            continue;
        vector<ll> ans(kmax + 1, 0);
        auto g = [&](int x, int k) -> ll {
            int y = k - x;
            if(x < 0 || x > Amax) return -LLONG_MAX / 2;
            if(y < 0 || y > Bmax) return -LLONG_MAX / 2;
            return fA[x] + fB[y];
        };
        for (int k = 1; k <= kmax; k++){
            int L = max({0, 2 * k - m, k - Bmax});
            int R = min({k, n - k, Amax});
            int lo = L, hi = R;
            while(lo < hi){
                int mid = lo + (hi - lo) / 2;
                if(g(mid, k) < g(mid + 1, k))
                    lo = mid + 1;
                else
                    hi = mid;
            }
            ans[k] = g(lo, k);
        }
        for (int k = 1; k <= kmax; k++)
            cout << ans[k] << (k == kmax ? "\n" : " ");
    }
    return 0;
}
