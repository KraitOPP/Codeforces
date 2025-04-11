#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 998244353

typedef long long ll;

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n, m, d;
        cin >> n >> m >> d;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        
        vector<int> lastPrefix(m, 0);
        lastPrefix[0] = (grid[n-1][0] == 'X');
        for (int j = 1; j < m; j++){
            lastPrefix[j] = lastPrefix[j-1] + (grid[n-1][j] == 'X');
        }
        
        vector<vector<int>> dp0(n, vector<int>(m, 0));
        vector<vector<int>> dp1(n, vector<int>(m, 0));
        
        for (int j = 0; j < m; j++){
            if(grid[n-1][j] == '#'){
                dp0[n-1][j] = 0;
                dp1[n-1][j] = 0;
            } 
            else {
                dp1[n-1][j] = 1;
                int L = max(0, j - d);
                int R = min(m - 1, j + d);
                int cnt = lastPrefix[R] - (L > 0 ? lastPrefix[L - 1] : 0);
                dp0[n-1][j] = cnt % MOD;
            }
        }
        
        int nextRange = (int)floor(sqrt((ll)d * d - 1));
        
        for (int i = n - 2; i >= 0; i--){
            vector<int> prefix_dp0(m, 0);
            prefix_dp0[0] = dp0[i+1][0];
            for (int j = 1; j < m; j++){
                prefix_dp0[j] = (prefix_dp0[j-1] + dp0[i+1][j]) % MOD;
            }
            
            vector<int> cur_dp1(m, 0);
            for (int j = 0; j < m; j++){
                if(grid[i][j] == '#'){
                    cur_dp1[j] = 0;
                } 
                else {
                    int L = max(0, j - nextRange);
                    int R = min(m - 1, j + nextRange);
                    int vertical = prefix_dp0[R] - (L > 0 ? prefix_dp0[L - 1] : 0);
                    vertical %= MOD;
                    if(vertical < 0) vertical += MOD;
                    cur_dp1[j] = vertical;
                }
            }
            dp1[i] = cur_dp1;
            
            vector<int> prefix_dp1(m, 0);
            prefix_dp1[0] = dp1[i][0];
            for (int j = 1; j < m; j++){
                prefix_dp1[j] = (prefix_dp1[j-1] + dp1[i][j]) % MOD;
            }
            
            vector<int> cur_dp0(m, 0);
            for (int j = 0; j < m; j++){
                if(grid[i][j] == '#'){
                    cur_dp0[j] = 0;
                } 
                else {
                    int L = max(0, j - d);
                    int R = min(m - 1, j + d);
                    int horiz = prefix_dp1[R] - (L > 0 ? prefix_dp1[L - 1] : 0);
                    horiz = (horiz - dp1[i][j]) % MOD;
                    if(horiz < 0) horiz += MOD;
                    
                    int L2 = max(0, j - nextRange);
                    int R2 = min(m - 1, j + nextRange);
                    int vertical = prefix_dp0[R2] - (L2 > 0 ? prefix_dp0[L2 - 1] : 0);
                    vertical %= MOD;
                    if(vertical < 0) vertical += MOD;
                    
                    cur_dp0[j] = (horiz + vertical) % MOD;
                }
            }
            dp0[i] = cur_dp0;
        }
        
        int res = 0;
        for (int j = 0; j < m; j++){
            if(grid[0][j] == 'X'){
                res = (res + dp0[0][j]) % MOD;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
