#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

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
        vi a(n);
        inp(a,n);
        vi pre(n+1,INT_MAX);
        map<int,vi> mp;
        for(int i=0;i<n;i++) mp[a[i]].push_back(i+1);
        for(auto itr : mp){
            int mnk = itr.second[0];
            for(int i=1;i<itr.second.size();i++){
                mnk = max(mnk, itr.second[i]-itr.second[i-1]);
            }
            mnk = max(mnk, n - itr.second[itr.second.size()-1]+1);
            if(mnk<=n) pre[mnk] = min(pre[mnk],itr.first);
        }

        int prv=INT_MAX;
        for(int i=1;i<=n;i++){
            prv = min(prv, pre[i]);
            
            if(prv==INT_MAX) cout<<-1<<" ";
            else cout<<prv<<" ";
        }
        cout<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}