#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
const int inf = 1e18, mod = 1e9 + 7;

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {

        int n, x;
        cin >> n >> x;
        vi a(n);
        inp(a, n);

        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[i]>1){
                mp[i+x]+=mp[i]-1;
            }
        }
        int mex=0;
        for(int i=0;i<n;i++){
            if(mp[i]<1) break;
            mex=i+1;
        }
        cout<<mex<<endl;
       

    }

    return 0;
}
