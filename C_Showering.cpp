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
        int n,s,m;
        cin>>n>>s>>m;
        int prv=0;
        int flag=0;
        for(int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
           
            if(l-prv>=s) flag=1;
            prv=r;
        }
        if(m-prv>=s) flag=1;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}