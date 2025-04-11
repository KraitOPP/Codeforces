#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>
#define ll long long
const int inf = 1e18, mod = 1e9+7;

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        inp(a, n);

        int curr = -1;
        queue<int> q; 
        vi result(n); 

        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() <= a[i]) {
                q.pop();
            }
            if ((int)q.size() > 11) {
                result[i] = a[i];
            } 
            else {
                if (curr < a[i]) {
                    curr = a[i] + 300;
                } 
                else {
                    curr += 300;
                }
                result[i] = curr;
                q.push(curr); 
            }
        }

        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
