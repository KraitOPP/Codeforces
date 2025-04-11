#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18, mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x, y;
    cin >> n >> x >> y;
    
    if (x > y) swap(x, y);
    
    int s = 0, e = 2 * 1e9;
    int res = -1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        int tasks = (mid / x) + (mid / y); 
        
        if (tasks >= n - 1) {
            res = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    
    cout << res + x << endl; 
    return 0;
}
