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
        
        int n;
        cin >> n;
        string s;
        cin >> s;

        map<char, int> mp1;
        map<char, int> mp2;

        vector<int> pre(n + 1, 0);
        vector<int> suff(n + 1, 0);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mp1[s[i]] == 0) {
                cnt++;
            }
            mp1[s[i]]++;
            pre[i] = cnt;
        }

        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (mp2[s[i]] == 0) {
                cnt++;
            }
            mp2[s[i]]++;
            suff[i] = cnt;
        }

        int ans = 0;
        mp1.clear();
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, pre[i] + suff[i + 1]);
        }

        cout << ans << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }

    return 0;
}
