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
        vector<int> a(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int mx=0;
        int mxnum=-1;
        int res=0;
        for(auto itr:mp){
            if(itr.first==0) continue;
            if(itr.second > mx){
                mx=itr.second;
                mxnum=itr.first;
            }
        }
        for(auto itr: mp){
            if(itr.first==0) continue;
            if(itr.first==mxnum){
                itr.second+=mp[0];
            }
            int x=itr.second;
            res+=(x*(x-1))/2;
        }
        if(res==0) cout<<mp[0]*(mp[0]-1)/2<<endl;
        else cout<<res<<endl;



        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   