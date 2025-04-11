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
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<int> a(n);
        map<int,vector<int>> mp;
        int x=-1,y=-1,x1,y1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]].push_back(i+1);
            if(x==-1) x=a[i], x1=i+1;
            if(y==-1 && a[i]!=x) y=a[i],y1=i+1;
        }

        if(mp.size()==1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(auto itr: mp){
                if(itr.first==x) continue;
                for(auto itr2: itr.second){
                    cout<<x1<<" "<<itr2<<endl;
                }
            }
            for(auto itr : mp[x]){
                if(itr==x1) continue;
                cout<<itr<<" "<<y1<<endl;
            }
        }



        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}