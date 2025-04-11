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
        int n, l, r;
        cin>>n>>l>>r;
        vector<int> a(n);
        for (int i=0;i<n;i++) cin>>a[i];

        int ans = 0;
        int currSum = 0;
        int i = 0;

        for (int j=0;j<n;j++) {
            currSum+=a[j];

            while(currSum>r && i<=j) {
                currSum-=a[i];
                i++;
            }
            if (currSum>=l && currSum<=r) {
                ans++;
                currSum=0; 
                i=j+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
