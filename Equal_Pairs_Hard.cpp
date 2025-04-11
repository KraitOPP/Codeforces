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
        int res=0;
        int prev=0;
        int prvcnt=0;
        int mxcnt=0,mx=-1;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;

            int z = mp[y];
            mp[y]++;
            res = prev;
            res-=z*(z-1)/2;
            res+=mp[y]*(mp[y]-1)/2;
            prev=res;
            if(mxcnt < mp[y]){
                mxcnt=mp[y];
                mx=y;
            }

            res-=mxcnt*(mxcnt-1)/2;
            res+= (mxcnt+n-i-1)*(mxcnt+n-i-2)/2;


            cout<<res<<" ";
        }
        cout<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}