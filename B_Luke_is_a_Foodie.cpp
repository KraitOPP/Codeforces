#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

pair<int, int> intervalIntersection(int a, int b, int c, int d) {
    int start = max(a, c);
    int end = min(b, d);

    if (start <= end) {
        return {start, end};
    } else {
        return {LLONG_MIN, LLONG_MIN}; // Use LLONG_MIN for clarity
    }
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        auto begin = chrono::high_resolution_clock::now();
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int ans = 0;
        int prvstart = LLONG_MIN;
        int prvend = LLONG_MAX;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            int start = a[i] - x;
            int end = a[i] + x;
            pair<int, int> intersection = intervalIntersection(prvstart, prvend, start, end);

            if(intersection.first == LLONG_MIN && intersection.second == LLONG_MIN) {
                ans++;
                prvstart = start;
                prvend = end;
            } 
            else {
                prvstart = intersection.first;
                prvend = intersection.second;
            }
        }
        cout << ans << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
