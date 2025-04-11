#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> pre(n, 0), suf(n, 0);
        set<int> seen;
        int mex = 0;

        for (int i = 0; i < n; i++) {
            seen.insert(a[i]);
            while (seen.count(mex)) {
                mex++;
            }
            pre[i] = mex;
        }

        seen.clear();
        mex = 0;

        for (int i = n - 1; i >= 0; i--) {
            seen.insert(a[i]);
            while (seen.count(mex)) {
                mex++;
            }
            suf[i] = mex;
        }

        int pos = -1;
        for (int i = 0; i < n - 1; i++) {
            if (pre[i] == suf[i + 1]) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << -1 << endl;
        } else {
            cout << 2 << endl;
            cout << 1 << " " << pos + 1 << endl;
            cout << pos + 2 << " " << n << endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }

    return 0;
}
