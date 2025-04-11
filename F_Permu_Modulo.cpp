#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)


const int mod = 1000000007;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,c;
        cin >> a >> c;
        int ans = (a+1)*(a+2)/2 * (c+1) + (c+1)*(c+2)/2*(a+1)- (a+1)*(c+1);        
        cout << ans%mod << endl;
    }
    return 0;
}