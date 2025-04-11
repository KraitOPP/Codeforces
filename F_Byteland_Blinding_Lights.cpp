#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18, mod = 1e9 + 7;

double findRoots(int a, int b, int c) {
    int d = b * b - 4 * a * c;
    if (d < 0) return -1; 

    double sqrt_d = sqrt(static_cast<double>(d));

    double root1 = (-b + sqrt_d) / (2.0 * a);
    double root2 = (-b - sqrt_d) / (2.0 * a);

    if (root1 >= 0 && root2 >= 0) {
        return min(root1, root2);
    } else if (root1 >= 0) {
        return root1;
    } else if (root2 >= 0) {
        return root2;
    }

    return -1; 
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        // auto begin = chrono::high_resolution_clock::now();

        int a, b, u, v;
        cin >> a >> b >> u >> v;
        int n;
        cin >> n;

        vector<pair<int, int>> cor(n);
        for (int i = 0; i < n; i++) {
            cin >> cor[i].first >> cor[i].second;
        }

        vector<pair<double, pair<int, int>>> pos;
        for (int i = 0; i < n; i++) {
            int x = cor[i].first, y = cor[i].second;
            int a1 = u * v;
            int b1 = u * y - u * b - v * x + v * a;
            int c1 = a * y - a * b + b * x;
            double root = findRoots(a1, b1, c1);

            if (root >= 0) { 
                pos.push_back({root, {x, i}});
            }
        }

        if (pos.empty()) {
            cout << -1 << endl;
        } else {
            sort(pos.begin(), pos.end());
            cout << pos[0].second.second + 1 << endl;
        }

        // auto end = chrono::high_resolution_clock::now();
        // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
