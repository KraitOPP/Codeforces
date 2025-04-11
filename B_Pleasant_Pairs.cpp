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
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]=i+1;
        }
        int res=0;
        for(int i=1;i<=2*n;i++){
            if(mp.find(i)==mp.end()) continue;
            for(int j=i+1;i*j<=2*n;j++){
                if(mp.find(j)==mp.end()) continue;
                int x=mp[i],y=mp[j];
                if((x+y)==(i*j)) res++;
            }
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   