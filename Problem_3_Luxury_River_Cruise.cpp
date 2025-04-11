#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

int dfs(int node, vector<vector<int>> &adj, vector<char> &s, int idx) {
    if (idx == s.size()) return node;
    int x = (s[idx] == 'L') ? 0 : 1;
    return dfs(adj[node][x], adj, s, idx + 1);
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    freopen("cruise.in", "r", stdin);
    cin >> n >> m >> k;
    vector<vector<int>> adj(n, vector<int>(2));
    
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[i][0] = u - 1; 
        adj[i][1] = v - 1;
    }
    
    vector<char> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    vector<int> arr(n, -1);
    for (int i = 0; i < n; i++) {
        arr[i] = dfs(i, adj, s, 0);
    }

    int slow = arr[0], fast = arr[arr[0]];

    while (slow != fast) {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }

    int cnt = 0;
    slow = 0;
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
        cnt++;
    }

    int cycleLength = 1;
    int cycleStart = slow;
    int temp = arr[slow];
    while (temp != cycleStart) {
        temp = arr[temp];
        cycleLength++;
    }

    freopen("cruise.out", "w", stdout);
    if (k <= cnt) {
        int tmp = 0;
        for (int i = 0; i < k; i++) {
            tmp = arr[tmp];
        }
        cout << tmp + 1 << endl; 
    } else {
        k -= cnt;
        k = k % cycleLength;
        int tmp = cycleStart;
        for (int i = 0; i < k; i++) {
            tmp = arr[tmp];
        }
        cout << tmp + 1 << endl; 
    }

    return 0;
}
