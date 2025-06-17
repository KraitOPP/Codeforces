#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int MAXN = 1000000;
    vector<int> dp(MAXN+1, 0);

    dp[1] = 2;
    dp[2] = 8;

    for(int i = 3; i <= MAXN; i++){
        ll x = (6LL * dp[i-1]) % MOD;
        ll y = (7LL * dp[i-2]) % MOD;
        dp[i] = int((x + MOD - y) % MOD);
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
