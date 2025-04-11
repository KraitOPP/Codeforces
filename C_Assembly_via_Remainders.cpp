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
        cin>>n;
        int mx=0;
        vector<int> x(n-1);
        loop(i,0,n-1){
            cin>>x[i];
            mx = max(mx,x[i]);
        }
        mx+=1;
        cout<<mx<<" ";
        loop(i,0,n-1){
            mx+=x[i];
            cout<<mx<<" ";
        }
        cout<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}