#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        auto begin = chrono::high_resolution_clock::now();
        int n,m;
        cin>>n>>m;
        int a[m];
        int prv=1;
        int ans=0;
        loop(i,0,m){
            cin>>a[i];
            if(a[i]>=prv) ans+=a[i]-prv;
            else{
                ans+=n-prv+a[i];
            }

            prv = a[i];
        }
        cout<<ans<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}