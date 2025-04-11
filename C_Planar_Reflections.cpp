#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int inf = 1e18, mod = 1e9 + 7;

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

        for (int i = 1; i <= n; i++) {
            dp[1][i][0] = 1; 
            dp[1][i][1] = 1; 
        }

        for (int i = 2; i <= k; i++) {
            for(int j=n;j>=1;j--){
                //Forward Direction
                dp[i][j][0] = 2;
                if (j < n) {
                    dp[i][j][0] += dp[i][j + 1][0] - 1;
                    dp[i][j][0] %= mod;
                }
                if (j > 1) {
                    dp[i][j][0] += dp[i - 1][j - 1][1] - 1;
                    dp[i][j][0] %= mod;
                }
            }
            for (int j = 1; j <= n; j++) {
                // Backward Direction
                dp[i][j][1] = 2;
                if (j < n) {
                    dp[i][j][1] += dp[i - 1][j + 1][0] - 1;
                    dp[i][j][1] %= mod;
                }
                if (j > 1) {
                    dp[i][j][1] += dp[i][j - 1][1] - 1;
                    dp[i][j][1] %= mod;
                }
            }
        }

        cout << dp[k][1][0] << endl;
    }
    return 0;
}
