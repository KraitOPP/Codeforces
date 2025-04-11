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
    int xsum=0,ysum=0,zsum=0;
    loop(i,0,n){
        int x,y,z;
        cin>>x>>y>>z;
        xsum+=x;
        ysum+=y;
        zsum+=z;
    }
    if(xsum==0 && ysum==0 && zsum==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}