#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int res=0;
        for(int i=30;i>=0;i--){
            int cnt=0;
            int num =1LL<<i;
            for(int j=0;j<n;j++){
                if((num&a[j])==0) cnt++;
            }
            if(cnt<=k){
                res=res|num;
                k-=cnt;
            }
        }
        cout<<res<<endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}