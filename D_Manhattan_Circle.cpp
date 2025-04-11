#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a; i<b; i++)

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        auto begin = chrono::high_resolution_clock::now();
        
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        loop(i, 0, n) {
            cin >> a[i];
        }
        
        int w1 = m, w2 = -1;
        int h1 = n, h2 = -1;
        
        loop(i, 0, n) {
            loop(j, 0, m) {
                if(a[i][j] == '#') {
                    w1 = min(w1, j);
                    w2 = max(w2, j);
                    h1 = min(h1, i);
                    h2 = max(h2, i);
                }
            }
        }
        
        cout << ((h1 + h2) / 2) + 1 << " " << ((w1 + w2) / 2) + 1 << endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    
    return 0;
}
