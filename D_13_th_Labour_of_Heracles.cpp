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
        vector<int> a(n);
        int sum=0;
        for(int i=0;i<n;i++){
             cin>>a[i];
             sum+=a[i];
        }
        vector<int> deg(n,0);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[deg[i]]=max(mp[deg[i]],a[i]);
        }
        cout<<sum<<" ";
        for(int i=2;i<=n-1;i++){
            sum+=mp[i];
            cout<<sum<<" ";
        }
        cout<<endl;



        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}