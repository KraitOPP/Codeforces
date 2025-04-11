#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int s = 2, e = 999;
        int res = -1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int expected = mid * mid;
            
            cout << "? " << mid << " " << mid << endl;
            cout.flush();
            
            int measured;
            cin >> measured;
            
            if (measured > expected) {
                res = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        if (res == -1) {
            res = 999;
        }
        
        cout << "! " << res << endl;
        cout.flush();
    }
    
    return 0;
}
