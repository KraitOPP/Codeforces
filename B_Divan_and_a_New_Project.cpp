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
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            int visit;
            cin>>visit;
            a.push_back({visit,i+1});
        }
        vector<int> res(n+1);
        res[0]=(n+1)/2-1;
        sort(a.begin(),a.end(),greater<pair<int,int>>());
        int ans=0;
        int i=res[0]+1;
        int j=res[0]-1;
        for(int k=0;k<n;k++){
            if((k+1)<n){
                res[a[k].second]=i;
                res[a[k+1].second]=j;
                ans+=a[k].first*abs(res[0]-i);
                ans+=a[k+1].first*abs(res[0]-j);
                i++,j--,k++;
            }
            else{
                res[a[k].second]=i;
                ans+=a[k].first*abs(res[0]-i);
                i++;
            }
        }
        cout<<ans*2<<endl;
        for(int i=0;i<=n;i++) cout<<res[i]<<" ";
        cout<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}