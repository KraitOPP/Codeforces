#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i = a; i < b; i++)

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();

        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        if (n % 2 == 1) {
            cout << -1 << endl;
        } else {
            vector<pair<int, int>> res;
            for (int i = 1; i < n; i+=2) {
                if (a[i] == a[i - 1]) {
                    res.push_back({i, i + 1});
                } else {
                    res.push_back({i, i});
                    res.push_back({i+1, i + 1});
                }
            }

            cout << res.size() << endl;
            for (auto &p : res) {
                cout << p.first << " " << p.second << endl;
            }
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }

    return 0;
}
