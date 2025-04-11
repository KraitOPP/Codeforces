#include <bits/stdc++.h>
using namespace std;

#define int long long

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
        map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        
        int ans = 0;
        int alice = 0;
        
        while (!mp.empty()) {
            if (alice == 0) alice = 1;
            
            for (auto it = mp.begin(); it != mp.end();) {
                ans++;
                alice--;
                it = mp.erase(it);
                if (alice == 0) break;
            }
            
            int uniq = 1;
            for (auto it = mp.begin(); it != mp.end();) {
                if (it->second <= uniq) {
                    alice += it->second - 1;
                    it = mp.erase(it);
                    break;
                } else {
                    uniq++;
                    ++it;
                }
            }
        }
        
        cout << ans << endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    
    return 0;
}
