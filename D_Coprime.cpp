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
        int a[n+1];
        map<int,int> idx;
        loop(i,1,n+1){
            cin>>a[i];
            idx[a[i]]=i;
        }
        int ans=-1;
        for(int i=1;i<=1000;i++){
            if(idx[i]==0) continue;
            for(int j=i;j<=1000;j++){
                if(idx[j]!=0 && __gcd(i,j)==1){
                    ans=max(ans,idx[i]+idx[j]);
                }
            }
        }
        cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}