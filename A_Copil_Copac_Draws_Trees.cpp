#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)

void solve(vector<vector<pair<int, int>>> &adj, int node, vector<int> &idx, vector<int> &dp){

    for (auto neigh : adj[node]){
        if (dp[neigh.first] == 0){
            int i = neigh.second;
            if (i <= idx[node]) dp[neigh.first] = 1 + dp[node];
            else dp[neigh.first] = dp[node];
            idx[neigh.first] = i;
            solve(adj, neigh.first, idx, dp);
        }
    }

    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dp(n, 0);
        vector<int> idx(n, 0);
        for (int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;

            adj[u - 1].push_back({v - 1, i});
            adj[v - 1].push_back({u - 1, i});
        }
        dp[0]=1;
        solve(adj, 0, idx, dp);
        int res = *max_element(dp.begin(), dp.end());
        cout << res << endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}