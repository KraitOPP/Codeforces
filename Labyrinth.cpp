#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

void bfs(vector<vector<char>> &a, int u, int v, int n, int m, int e1, int e2) {
    queue<pair<int,int>> q;
    q.push({u,v});
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    char dir[4] = {'R', 'L', 'D', 'U'}; 
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> prv(n, vector<pair<int,int>>(m, {-1, -1}));
    
    vis[u][v] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] != '#' && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
                prv[nx][ny] = {x, y}; 
                if (nx == e1 && ny == e2) {
                    break;
                }
            }
        }
    }

    if (vis[e1][e2]) {
        cout << "YES" << endl;
        string res;
        int x = e1, y = e2;

        while (x != u || y != v) {
            pair<int, int> p = prv[x][y];
            int px = p.first, py = p.second;

            if (x == px + 1 && y == py) res.push_back('D');
            else if (x == px - 1 && y == py) res.push_back('U');
            else if (x == px && y == py + 1) res.push_back('R');
            else if (x == px && y == py - 1) res.push_back('L');

            x = px;
            y = py;
        }

        reverse(res.begin(), res.end());
        cout<<res.size()<<endl;
        cout << res << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    
    int u, v, x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                u = i; v = j;
            } else if (a[i][j] == 'B') {
                x = i; y = j;
            }
        }
    }
    
    bfs(a, u, v, n, m, x, y);

    return 0;
}
