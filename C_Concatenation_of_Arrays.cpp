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
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
        }

        sort(a.begin(),a.end(), [&](pair<int,int> &a, pair<int,int> &b){
            int cnt1=0,cnt2=0;
            vector<int> tmp1 = {a.first,a.second,b.first,b.second};
            for(int i=0;i<4;i++){
                for(int j=i+1;j<4;j++){
                    if(tmp1[i] > tmp1[j]) cnt1++;
                }
            }
            vector<int> tmp2 = {b.first,b.second, a.first,a.second};
            for(int i=0;i<4;i++){
                for(int j=i+1;j<4;j++){
                    if(tmp2[i] > tmp2[j]) cnt2++;
                }
            }
            if(cnt1==cnt2){
                min(a.first,a.second) < min(b.first,b.second);
            }
            return cnt1<cnt2;
        });

        for(int i=0;i<n;i++) cout<<a[i].first<<" "<<a[i].second<<" ";
        cout<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}