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
        int n;
        cin>>n;
        int sc1=0,sc2=0;
        int mx1=0,mx2=0;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i+=2){
            sc1++;
            mx1=max(mx1,a[i]);
        }
        for(int i=1;i<n;i+=2){
            sc2++;
            mx2=max(mx2,a[i]);
        }
        cout<<max(mx1+sc1,mx2+sc2)<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}