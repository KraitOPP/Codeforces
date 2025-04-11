#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define vi vector<int>

int getParent(vi &par, int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = getParent(par, par[x]); 
}

void unionG(vi &par, vi &rank, vi &size, int x, int y) {
    int px = getParent(par, x);
    int py = getParent(par, y);

    if (px != py) {
        if (rank[px] > rank[py]) {
            par[py] = px;
            size[px] += size[py];
        } else if (rank[px] < rank[py]) {
            par[px] = py;
            size[py] += size[px]; 
        } else {
            par[py] = px;
            size[px] += size[py];
            rank[px]++;
        }
    }
}

signed main() {
    fastio();

    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int totalCells = n * m;
    vi par(totalCells), rank(totalCells, 0), size(totalCells, 1);

    for (int i = 0; i < totalCells; i++) {
        par[i] = i;
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(mat[i][j]=='*'){
                size[i*m+j] = 0;
                continue;
            }
            for (auto dir : directions) {
                int ni = i + dir.first, nj = j + dir.second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj]!='*') {
                    int cell1 = i * m + j;
                    int cell2 = ni * m + nj;
                    unionG(par, rank, size, cell1, cell2);
                }
            }
        }
    }
    vector<vector<char>> res(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = mat[i][j];
            if (mat[i][j] == '.') continue;

            int tempSize = 1;
            set<int> uniqueParents;

            for (auto dir : directions) {
                int ni = i + dir.first, nj = j + dir.second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == '.') {
                    int neighborParent = getParent(par, ni * m + nj);
                    uniqueParents.insert(neighborParent);
                }
            }

            for (int parent : uniqueParents) {
                tempSize += size[parent];
            }

            res[i][j] = (tempSize % 10) + '0'; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }
    return 0;
}
