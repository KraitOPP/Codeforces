#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> xorVal(1000000,0);
    for(int i=1;i<1000000;i++) xorVal[i]=xorVal[i-1]^i;
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int mex,xorr;
        cin>>mex>>xorr;
        int curr=xorVal[mex-1];
        if(curr==xorr) cout<<mex<<endl;
        else{
            curr=curr^xorr;
            if(curr==mex) cout<<mex+2;
            else cout<<mex+1;
            cout<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}