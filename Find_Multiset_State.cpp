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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int mx=a[n-1]+a[0];
        a.pop_back();        
        int i=1;
        while(i<k){
            mx+=a[i];
            i++;
        }
        a.push_back(mx);
        for(int j=i;j<a.size();j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}