#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

int iterativeSolve(string &a, string &b, string &c) {
    int n = a.size(), m = b.size(), l = c.size();

    vector<vi> dp(n + 1, vi(m + 1, 0));

    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i + j == l) continue;

            if (i == n) {
                int res = 0;
                for (int k = j; k < m; k++) {
                    if (b[k] == c[i + k]) res++;
                }
                dp[i][j] = res;
                continue;
            }

            if (j == m) {
                int res = 0;
                for (int k = i; k < n; k++) {
                    if (a[k] == c[k + j]) res++;
                }
                dp[i][j] = res;
                continue;
            }

            if (a[i]==c[i+j] && b[j]==c[i+j]) {
                dp[i][j] = max(1 + dp[i+1][j], 1 + dp[i][j+1]);
            } 
            else if (a[i] == c[i+j]) {
                dp[i][j] = max(1 + dp[i+1][j], dp[i][j+1]);
            } 
            else if (b[j] == c[i+j]) {
                dp[i][j] = max(dp[i+1][j], 1 + dp[i][j+1]);
            } 
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();

        string a, b, c;
        cin >> a >> b >> c;
        cout << c.size() - iterativeSolve(a, b, c) << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }

    return 0;
}
