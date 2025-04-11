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
        vector<int> a(n);
        vector<int> pre;
        pre.push_back(0);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            pre.push_back(sum);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                vector<int> grps;
                for(int j=i;j<=n;j+=i){
                    grps.push_back(pre[j]-pre[j-i]);
                }
                sort(grps.begin(),grps.end());
                ans=max(ans,grps[grps.size()-1]-grps[0]);
            }
        }  
        cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   