#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int find(vector<int> &parent, int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent, parent[node]);
}

void uni(int x, int y, vector<int> &size, vector<int> &parent) {
    int parx = find(parent, x);
    int pary = find(parent, y);
    if (parx == pary) return;

    if (size[parx] < size[pary]) {
        parent[parx] = pary;
        size[pary] += size[parx]; 
    } else {
        parent[pary] = parx;
        size[parx] += size[pary];
    }
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    auto begin = chrono::high_resolution_clock::now();

    int n, m;
    cin >> n >> m;
    vector<int> size(n + 1, 1);
    vector<int> parent(n + 1);
    
    for (int i = 1; i <= n; i++) parent[i] = i;

    while (m--) {
        int k;
        cin >> k;
        vector<int> tmp(k);
        for (int i = 0; i < k; i++) cin >> tmp[i];
        for (int i = 1; i < k; i++) {
            uni(tmp[i-1], tmp[i], size, parent);
        }
    }

    for (int i = 1; i <= n; i++) {
        int parent_i = find(parent, i);
        cout << size[parent_i] << " ";
    }
    cout << endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;

    return 0;
}
