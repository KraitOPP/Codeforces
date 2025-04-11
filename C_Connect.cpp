#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define pii pair<int, int>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y, int n, int m, vector<string> &grid, vector<vector<bool>> &visited) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '0' && !visited[x][y]);
}

void dfs(int x, int y, vector<string> &grid, vector<vector<bool>> &visited, vector<pii> &component) {
    int n = grid.size();
    int m = grid[0].size();
    visited[x][y] = true;
    component.push_back({x, y});
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (isValid(nx, ny, n, m, grid, visited)) {
            dfs(nx, ny, grid, visited, component);
        }
    }
}

int findMinDistance(vector<pii> &comp1, vector<pii> &comp2) {
    int minDist = LLONG_MAX;
    for (auto &p1 : comp1) {
        for (auto &p2 : comp2) {
            int dist = (p1.first - p2.first) * (p1.first - p2.first) +
                       (p1.second - p2.second) * (p1.second - p2.second);
            minDist = min(minDist, dist);
        }
    }
    return minDist;
}

signed main() {
    fastio();
    int n;
    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pii> component1, component2;

    dfs(r1, c1, grid, visited, component1);

    if (visited[r2][c2]) {
        cout << 0 << endl;
        return 0;
    }

    dfs(r2, c2, grid, visited, component2);

    int minDist = findMinDistance(component1, component2);
    cout << minDist << endl;

    return 0;
}
