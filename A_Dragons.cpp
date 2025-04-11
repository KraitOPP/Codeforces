#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        auto begin = chrono::high_resolution_clock::now();
        int s,n;
        cin>>s>>n;
        vector<vector<int>> a(n,vector<int>(2));
        loop(i,0,n) cin>>a[i][0]>>a[i][1];
        sort(a.begin(),a.end());
        int f=1;
        loop(i,0,n){
            if(a[i][0]>=s){
                f=0;
                break;
            }
            s+=a[i][1];
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}