#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            int mn=min(x,y);
            if(y>=-1 || (y>=0 && y%2==0)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}