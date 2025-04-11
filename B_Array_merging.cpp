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
        cin >> n;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int ans = 1;
        map<int,int> mp1;
        int prv = a[0];
        mp1[a[0]]=1;
        int cnt=1;
        loop(i,1,n){
            if(a[i]==prv){
                cnt++;
            }
            else cnt=1;
            mp1[a[i]]=max(mp1[a[i]],cnt);
            prv = a[i];
        }
        map<int,int> mp2;
        prv = b[0];
        mp2[b[0]]=1;
        cnt=1;
        loop(i,1,n){
            if(b[i]==prv){
                cnt++;
            }
            else cnt=1;
            mp2[b[i]]=max(mp2[b[i]],cnt);
            prv = b[i];
        }
        for(auto itr:mp1){
            ans = max(ans,mp1[itr.first]+mp2[itr.first]);
        }
        for(auto itr:mp2){
            ans = max(ans,mp1[itr.first]+mp2[itr.first]);
        }
        cout<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   