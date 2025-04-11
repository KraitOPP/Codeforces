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
        int n,k;
        cin>>n>>k;
        vector<int> ans(n+1,-1);
        int i=1;
        while(i*k < n){
            ans[i*k]=i;
            i++;
        }
        int st=n;
        for(int i=1;i<=n;i++){
            if(ans[i]==-1){
                ans[i]=st;
                st--;
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   