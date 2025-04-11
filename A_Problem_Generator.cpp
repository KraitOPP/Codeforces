#include <bits/stdc++.h>
using namespace std;
#define int long long
#define input(i, n, a) for(int i=0;i<n;i++) cin>>a[i]

signed main(){ 
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        char a[n];
        int i = 0;
        input(i, n, a);
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[a[i]]++;
        }
        int ans = 0;
        for(char ch = 'A'; ch <= 'G'; ch++) {
            ans += max(0ll, m - mp[ch]);
        }
        cout << ans << endl;
    }
    return 0;
}