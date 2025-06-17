#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int best = 0;

            if (a[i-1] == b[j-1]) {
                best = max(best, dp[i-1][j-1] + 2);
            }

            best = max(best, dp[i-1][j] - 1);
            best = max(best, dp[i][j-1] - 1);

            dp[i][j] = max(best, 0);

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";
    return 0;
}
