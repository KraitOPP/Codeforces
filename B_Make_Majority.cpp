#include <bits/stdc++.h>
using namespace std;

#define int long long

void vis(vector<string>& s, map<pair<int, int>, int>& visited, int i, int j) {
    int n = s[0].length();
    if (i < 0 || i >= 2 || j < 0 || j >= n || visited[{i, j}] || s[i][j] == 'x') return;
    visited[{i, j}] = 1;
    vis(s, visited, i + 1, j);
    vis(s, visited, i - 1, j);
    vis(s, visited, i, j + 1);
    vis(s, visited, i, j - 1);
}

int count_regions(vector<string>& s) {
    map<pair<int, int>, int> visited;
    int n = s[0].length();
    int regions = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[{i, j}] && s[i][j] == '.') {
                regions++;
                vis(s, visited, i, j);
            }
        }
    }
    return regions;
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
        vector<string> s(2);
        cin >> s[0] >> s[1];

        int initial_regions = count_regions(s);
        int count = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '.') {
                    s[i][j] = 'x'; 
                    int new_regions = count_regions(s);
                    if (new_regions == 3) {
                        count++;
                    }
                    s[i][j] = '.';
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
