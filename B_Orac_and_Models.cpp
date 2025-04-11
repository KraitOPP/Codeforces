#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
vector<vector<int>> factors(100001);
vector<int> primes;

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
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int> pre(n+1,1);
        for(int i=1;i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                if(a[j]>a[i]){
                    pre[j]=max(pre[j],pre[i]+1);
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++) res=max(res,pre[i]);
        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}