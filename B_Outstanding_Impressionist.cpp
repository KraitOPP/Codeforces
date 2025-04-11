#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
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
        vpii a;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            a.push_back({l,r});
            if(l==r){
                mp[l]++;
            }
        }
        string res="";
        set<int> notactive;
        for(int i=1;i<=2*n;i++){
            if(mp.find(i)==mp.end()){
                notactive.insert(i);
            }
        }
        for(int i=0;i<n;i++){
            int l=a[i].first,r=a[i].second;
            if(l==r && mp[l]>1){
                res+='0';
            }
            else if(l==r && mp[l]==1){
                res+='1';
            }
            else{
                bool flg=true;
                auto nt = notactive.lower_bound(l);
                if(nt!=notactive.end() && *nt<=r) flg=false;
                if(flg) res+='0';
                else res+='1';
            }
            
        }

        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}