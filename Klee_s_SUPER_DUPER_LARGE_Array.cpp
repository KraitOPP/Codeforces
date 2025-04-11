#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

int calc(int n, int k, int i) {
    return abs(n * k + n * (n - 1) / 2 - 2 * (i * k + i * (i - 1) / 2));
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();
        int n, k;
        cin >> n >> k;
        
        int low = 1, high = n;
        int res = INT_MAX;
        while (low <= high) {  
            int mid = low + (high - low) / 2;
            int val1 = calc(n, k, mid);
            int val2 = calc(n, k, mid + 1);
            
            res = min(res, val1);
            
            if (val1 >= val2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << res << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
