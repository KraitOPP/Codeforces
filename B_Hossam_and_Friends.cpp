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
        int n,m;
        cin>>n>>m;
        vector<int> a(n+1,n);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            if(u>v) swap(u,v); 
            a[u]=min(a[u],v-1);
        }
        int res=0;
        for(int i=n-1;i>0;i--){
            a[i]=min(a[i],a[i+1]);
        }
        for(int i=1;i<=n;i++) res+=a[i]-i+1;
        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}