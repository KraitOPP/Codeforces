#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    inp(a,n);
    map<int,int> mp;
    vector<vector<int>> res(n);
    int idx=0;
    for(int i=0;i<n;i++){
        auto itr = mp.lower_bound(a[i]);
        // --itr;
        if(itr==mp.begin()){
            mp[a[i]]=idx++;
            res[mp[a[i]]].push_back(a[i]);
        }
        else{
            --itr;
            res[itr->second].push_back(a[i]);
            mp[a[i]]=itr->second;
            mp.erase(itr);
        }
    }

    for(int i=0;i<n;i++){
        if(res[i].size()>0){
            for(int j=0;j<res[i].size();j++) cout<<res[i][j]<<" ";
            cout<<endl;
        }
    }

    return 0;
}