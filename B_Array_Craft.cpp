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
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> a(n,1);
        for(int i=1;i<=y-2;i+=2) a[i]=-1;
        if((y-2)>=0) a[y-2]=-1;
        for(int i=n-2;i>=x;i-=2) a[i]=-1;
        if(x<n) a[x]=-1;

        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}