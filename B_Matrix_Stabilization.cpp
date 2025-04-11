#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        auto begin = chrono::high_resolution_clock::now();
        
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bool f = true;
                int maxi = LLONG_MIN; 
                if(i-1 >= 0) {
                    maxi = max(maxi,a[i-1][j]);
                    if(a[i-1][j] >= a[i][j]) f=false;
                }
                if(j-1 >= 0) {
                    maxi = max(maxi,a[i][j-1]);
                    if(a[i][j-1] >= a[i][j]) f=false;
                }
                if(i+1 < n) {
                    maxi = max(maxi,a[i+1][j]);
                    if(a[i+1][j] >= a[i][j]) f=false;
                }
                if(j+1 < m) {
                    maxi = max(maxi,a[i][j+1]);
                    if(a[i][j+1] >= a[i][j]) f=false;
                }
                if (f) {
                    a[i][j] = maxi;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }   
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
