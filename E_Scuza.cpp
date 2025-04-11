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
        int n,q;
        cin>>n>>q;
        vector<int> a(n),pre(n,0);
        vector<pair<int,int>> b;
        vector<int> tmp;
        int prv=0;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            pre[i]=sum;
            if(a[i]>=prv){
                b.push_back({a[i],i});
                tmp.push_back(a[i]);
                prv=a[i];
            }
        }

        for(int i=0;i<q;i++){
            int x;
            cin>>x;
            int idx = upper_bound(tmp.begin(),tmp.end(),x)-tmp.begin();
            int ans;
            if(idx>=tmp.size()) ans=a.size();
            else ans=b[idx].second;
            if(ans-1 < 0) cout<<"0 ";
            else cout<<pre[ans-1]<<" ";
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}