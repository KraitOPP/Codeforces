#include <bits/stdc++.h>
using namespace std;
#define int long long


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
        vector<string> s(2);
        cin >> s[0] >> s[1];
        int cnt=0;
        for (int i = 0; i < n; i++) {
            if(s[0][i]=='.' && s[1][i]=='.'){
                bool top = (i-1>=0 && s[1][i-1]=='x' && s[0][i-1]!='x') && (i+1<n && s[1][i+1]=='x' && s[0][i+1]!='x');
                bool btm = (i-1>=0 && s[0][i-1]=='x' && s[1][i-1]!='x') && (i+1<n && s[0][i+1]=='x' && s[1][i+1]!='x');

                if(top || btm) cnt++;
            }
        }
        cout<<cnt<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
