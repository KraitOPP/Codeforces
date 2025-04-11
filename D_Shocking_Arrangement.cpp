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
        vi a(n), res, pos, neg;
        int cnt0=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0){
                cnt0++;
                res.push_back(0);
            }
            else if(a[i]>0) pos.push_back(a[i]);
            else neg.push_back(a[i]);
        }
        if(cnt0==n) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            int i=0, j=0;
            int sum=0;
            while(i<pos.size() || j<neg.size()){
                if(i<pos.size() && sum<=0){
                    sum+=pos[i];
                    res.push_back(pos[i]);
                    i++;
                }
                else{
                    sum+=neg[j];
                    res.push_back(neg[j]);
                    j++;
                }
            }
            for(int i=0;i<n;i++) cout<<res[i]<<" ";
            cout<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}