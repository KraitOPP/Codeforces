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
        int idx=-1,mn=INT_MAX;
        int minm=INT_MAX;
        int ans=0;
        vector<vector<int>> a;
        loop(i,0,n){
            int m;
            cin>>m;
            vector<int> tmp(m);
            loop(j,0,m){
                cin>>tmp[j];
                minm=min(minm,tmp[j]);
            }
            sort(tmp.begin(),tmp.end());
            if(tmp[1] < mn){
                mn=tmp[1];
                idx=i;
            }
            ans+=tmp[1];
            a.push_back(tmp);
        }
        cout<<ans-a[idx][1]+minm<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}