#include <bits/stdc++.h>
using namespace std;
#define int long long
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
        vector<int> a(n*(n-1)/2);
        for(int i=0;i<n*(n-1)/2;i++) cin>>a[i];
        sort(a.begin(),a.end());
        
        int x=n-1;
        vector<int> ans;
        int i=0;
        while(i<n*(n-1)/2){
            ans.push_back(a[i]);
            i+=x;
            x-=1;
        }
        ans.push_back(a[n*(n-1)/2-1]);
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}