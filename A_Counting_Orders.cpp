#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)
#define mod 1000000007

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=1;
        int j=n-1;
        int i=n-1;
        while(j>=0){
            while(i>=0 && a[i]>b[j]){
                i--;
            }
            int cnt=n-1-i;
            int pos=n-1-j;
            ans=((ans%mod)*((cnt-pos)%mod))%mod;
            j--;
        }
        cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}