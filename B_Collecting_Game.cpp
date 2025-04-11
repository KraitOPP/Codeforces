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
        vector<pair<int,int>> b;
        for(int i=0;i<n;i++){
            cin>>a[i];
            b.push_back({a[i],i});
        }
        sort(b.begin(),b.end());
        int sum=0;
        vector<int> pre(n);
        for(int i=0;i<n;i++){
            pre[i]=sum;
            sum+=b[i].first;
        }
        vector<int> suff(n);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            suff[i]=cnt;
            if(b[i].first <= pre[i]) cnt++;
            else cnt=0;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[b[i].second]=i+suff[i];
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}