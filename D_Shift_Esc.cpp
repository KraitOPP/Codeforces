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

int solve(vector<vector<int>> &grid, int n, int m, int k){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, inf)));
    vector<vector<int>> res(n, vector<int> (m,inf));
    for(int i=0;i<m;i++){
        dp[0][0][i] = i*k+grid[0][i];
        res[0][0]=min(res[0][0], dp[0][0][i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int s=0;s<m;s++){
                if(i==0 && j==0) continue;
                dp[i][j][s] = (j>0) ? dp[i][j-1][s] : inf;
                int num = (i>0) ? res[i-1][j] : inf;
                dp[i][j][s] = min(dp[i][j][s], num+k*s)+grid[i][(j+s)%m];
                res[i][j] = min(res[i][j], dp[i][j][s]);
            }
        }
    }
    return res[n-1][m-1];
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        cout<<solve(grid,n,m,k)<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}