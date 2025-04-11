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
        int x1,y1;
        cin>>x1>>y1;
        int x2,y2;
        cin>>x2>>y2;
        if(x1>=y1 && x2<=y2) cout<<"NO"<<endl;
        else if(y1>=x1 && y2<=x2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}