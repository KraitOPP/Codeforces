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
        int cnt=0;
        vector<int> ans;
        vector<int> bits(64,0);
        int tmp=n,i=0;
        while(tmp>0){
            bits[i] = tmp%2;
            tmp/=2;
            i++;
        }
        ans.push_back(n);
        for(int i=0;i<64;i++){
            if(bits[i]==1){
                int x = (1LL)<<i;
                int t1 = n^x;
                if(t1>0) ans.push_back(t1);
            }
        }
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
        cout<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}