#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto begin = chrono::high_resolution_clock::now();

    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    map<int,int> mp;
    loop(i,0,n){
        cin>>a[i];
        mp[a[i]]++;
    } 
    for(int i=0;i<q;i++){
        int p,x;
        cin>>p>>x;
        int t1 = a[p-1];
        mp[x]++;
        mp[t1]--;
        a[p-1]=x;
        int ans=0;
        int prv=0;
        map<int,int> pre;
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            pre[it->first] = it->second+prv;
            prv=it->second;
        }
        for(auto itr:pre){
            ans+=itr.first*itr.second;
        }
        cout<<ans<<endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}