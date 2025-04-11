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
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if(s[i]=='0'){
                for(int j=i+1;j<=n;j+=i+1){
                    if(s[j-1]=='1') break;
                    if(mp[j-1]==1) continue;
                    res+=i+1;
                    mp[j-1]=1;
                }
            }
        }
        cout << res << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}