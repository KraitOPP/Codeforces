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
        int w,h;
        cin>>w>>h;
        int hori=0,verti=0;
        for(int i=0;i<2;i++){
            int k;
            cin>>k;
            vector<int> a(k);
            for(int i=0;i<k;i++) cin>>a[i];
            hori=max(hori,a[k-1]-a[0]);
        }
        for(int i=0;i<2;i++){
            int k;
            cin>>k;
            vector<int> a(k);
            for(int i=0;i<k;i++) cin>>a[i];
            verti=max(verti,a[k-1]-a[0]);
        }
        int res=max(hori*h,verti*w);
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}