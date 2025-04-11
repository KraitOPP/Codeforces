#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int N = 1001;
int n, m, t1, t2;
int d1[N][N], d2[N][N];
char a[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    cin >> n >> m;
    queue<vector<int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                t1 = i, t2 = j;
            } else if (a[i][j] == 'M') {
                q.push({i, j, 0});
            }
        }
    }

    if (t1 == n - 1 || t2 == m - 1 || t1 == 0 || t2 == 0) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d1[i][j] = -1;
            d2[i][j] = -1;
        }
    }

    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        int x = v[0], y = v[1], d = v[2];
        if (d1[x][y] != -1) continue; 
        d1[x][y] = d;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#' || d1[nx][ny] != -1) continue;
            q.push({nx, ny, d + 1});
        }
    }

    q.push({t1, t2, 0});
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        int x = v[0], y = v[1], d = v[2];
        d2[x][y] = d;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '#' || d2[nx][ny] != -1) continue;

            if (d1[nx][ny] != -1 && d + 1 >= d1[nx][ny]) continue;

            par[nx][ny] = {x, y};
            if (nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1) {
                cout << "YES" << endl;
                string res;

                while (nx != t1 || ny != t2) {
                    pair<int, int> p = par[nx][ny];
                    int px = p.first, py = p.second;

                    if (nx == px + 1 && ny == py) res.push_back('D');
                    else if (nx == px - 1 && ny == py) res.push_back('U');
                    else if (nx == px && ny == py + 1) res.push_back('R');
                    else if (nx == px && ny == py - 1) res.push_back('L');

                    nx = px;
                    ny = py;
                }

                reverse(res.begin(), res.end());
                cout << res.size() << endl;
                cout << res << endl;
                return;
            }
            q.push({nx, ny, d + 1});
        }
    }

    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
