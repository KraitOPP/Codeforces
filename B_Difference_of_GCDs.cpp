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
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> ans;
        int f=1;
        for(int i=1;i<=n;i++){
            int k = (l+i-1)/i;
            k=k*i;
            if(k<=r) ans.push_back(k);
            else{
                f=0;
                break;
            }
        }
        if(f==0) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}