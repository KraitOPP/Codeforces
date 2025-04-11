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
        vector<int> a(n),b(n),res;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int mx=LLONG_MIN;
        for(int i=0;i<n;i++){
            a[i]=a[i]-b[i];
            mx=max(mx,a[i]);
        }
        for(int i=0;i<n;i++){
            if(a[i]==mx) res.push_back(i+1);
        }
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}