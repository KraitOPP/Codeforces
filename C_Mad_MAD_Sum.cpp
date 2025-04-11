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
        vector<int> a(n);
        int sum=0,mx=0,cnt=0,prv=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
            
            sum+=a[i]*mp[a[i]]+prv;
            prv=a[i]*mp[a[i]];
        }
        cout<<sum<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}