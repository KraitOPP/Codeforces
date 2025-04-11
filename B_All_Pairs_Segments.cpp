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
        int n,q;
        cin>>n>>q;
        vector<int> a(n),b(n);
        map<int,int> mp;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            b[i]=(n-1-i)*(i+1)+i;
            // cout<<b[i]<<" ";
        }
        // cout<<endl;
        // mp[b[n-1]]++;
        // for(int i=0;i<n-1;i++){
        //     mp[b[i]]+=a[i+1]-a[i];
        // }
        mp[b[0]]++;
        for(int i=1;i<n;i++){
            mp[i*(n-i)]+=a[i]-a[i-1]-1;
            mp[b[i]]++;
        }

        for(int i=0;i<q;i++){
            int qu;
            cin>>qu;
            cout<<mp[qu]<<" ";
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}