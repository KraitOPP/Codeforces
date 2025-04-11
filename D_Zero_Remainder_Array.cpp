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
    while(t--) {
        auto begin = chrono::high_resolution_clock::now();
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = (k - a[i] % k) % k;
            if(a[i] != 0) mp[a[i]]++;
        }
        
        int res = 0;
        vector<int> x;
        x.push_back(0);
        
        while(!mp.empty()) {
            auto itr = mp.begin();
            while(itr != mp.end()) {
                x.push_back(itr->first);
                itr->second--;
                if(itr->second == 0) {
                    itr = mp.erase(itr);
                } else {
                    ++itr;
                }
            }
        }
        
        for(int i = 1; i < x.size(); i++) {
            if(x[i] > x[i-1]) {
                res += x[i] - x[i-1];
            } else {
                res += x[i] + k - x[i-1];
            }
        }
        if(res!=0) cout << res+1<< endl;
        else cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    
    return 0;
}
