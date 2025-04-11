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
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i]>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int res=1;
        if(n%2==1) res=1;
        else{
            res = (a[n/2]-a[n/2-1]+1)*(b[n/2]-b[n/2-1]+1);
        }
        cout<<res<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}