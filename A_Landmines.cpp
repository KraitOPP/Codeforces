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

vector<pii> directions = {
    {-1,0}, {1, 0}, {0, -1}, {0, 1},
};

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<pii, int>> q;
    vector<vector<int>> minDist(n, vector<int>(m, inf)); 

    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) {
            q.push({{i, 0}, 0});
            minDist[i][0] = 0;
        }
    }

    int minPathLength = inf;

    while (!q.empty()) {
        auto top = q.front();
        pii cell = top.first;
        int dist = top.second;
        int row = cell.first, col = cell.second;
        q.pop();

        if (col == m - 1) {
            minPathLength = min(minPathLength, dist);
            continue;
        }

        for (auto dir : directions) {
            int dx = dir.first, dy = dir.second;
            int newRow = row + dx;
            int newCol = col + dy;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == 1 && ((dist + 1) < minDist[newRow][newCol])) {
                minDist[newRow][newCol] = dist + 1;
                q.push({{newRow, newCol}, dist + 1});
            }
        }
    }

    return (minPathLength == inf ? -1 : minPathLength);
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vi> a(n, vi(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if(a[i][j]==0) a[i][j]=-1;
            }
        }
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    int nwx = i+dx[k],nwy = j+dy[k];
                    if(nwx<0 || nwx>=n || nwy<0 || nwy>=n || a[i][j]!=-1) continue;
                    if(a[nwx][nwy]==1) a[nwx][nwy]=0;
                }
                if(a[i][j]==-1) a[i][j]=0;
            }
        }

        cout << shortestPathBinaryMatrix(a) << endl;
    }
    return 0;
}
