#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();

        int n, m;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        loop(i,0,n) cin>>a[i];
        loop(i,0,n) cin>>b[i];
        cin >> m;
        vector<int> d(m);
        loop(i,0,m) cin>>d[i];

        int flag = 1;
        map<int, int> mp;
        map<int, int> mp2;
        for (int i = 0; i < m; i++) mp[d[i]]++;

        for (int i = 0; i < n; i++) {
            mp2[b[i]]++;
            if (a[i] == b[i]) continue;
            else if (mp[b[i]] > 0) {
                mp[b[i]]--;
                continue;
            } else {
                flag = 0;
                break;
            }
        }

        if (flag) {
            int cnt = 0;
            for (auto itr : mp) {
                if (itr.second > 0 && mp2[itr.first] == 0) cnt++;
            }
            if ((cnt > 0 && mp2[d[m - 1]]) || (cnt == 0)) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else cout << "NO" << endl;

        auto end = chrono::high_resolution_clock::now(); // End time measurement
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    }
    return 0;
}
