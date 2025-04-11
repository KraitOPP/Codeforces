#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define INF 1e18

struct State {
    int x, y, dir, steps;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

signed main() {
    fastio();
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start, target;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j};
            }
            if (grid[i][j] == 'T') {
                target = {i, j};
            }
        }
    }

    vector<vector<vector<vector<bool>>>> visited(
        n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(4, false)))
    );

    queue<State> q;
    q.push({start.first, start.second, -1, 0}); 
    visited[start.first][start.second][0][0] = true;

    int steps = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int x,y,prev_dir, cnt;
            auto tmp = q.front();
            q.pop();
            x=tmp.x;
            y=tmp.y;
            prev_dir=tmp.dir;
            cnt=tmp.steps;
            if (grid[x][y]=='T') {
                cout << steps << endl;
                return 0;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                int new_cnt = (d == prev_dir) ? cnt + 1 : 1;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == '#' || new_cnt > 3)
                    continue;

                if (!visited[nx][ny][d][new_cnt]) {
                    visited[nx][ny][d][new_cnt] = true;
                    q.push({nx, ny, d, new_cnt});
                }
            }
        }

        steps++;
    }

    cout << -1 << endl;
    return 0;
}
