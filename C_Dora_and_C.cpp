#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int mx1=INT_MIN,mx2=INT_MIN,mn1=INT_MAX,mn2=INT_MAX;
        for(int i=0;i<n;i++){
            mx1 = max(mx1,max(a[i]%x,x-a[i]%x));
            mn1 = min(mn1,min(a[i]%x,x-a[i]%x));

            mx2 = max(mx2,max(a[i]%y,y-a[i]%y));
            mn2 = min(mn2,min(a[i]%y,y-a[i]%y));
        }
        int ans = min(mx1-mn1,mx2-mn2);
        cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}