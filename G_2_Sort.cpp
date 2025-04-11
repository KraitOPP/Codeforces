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
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n-1;i++){
            b[i]=(a[i]<2*a[i+1]) ? 1:0;
        }
        int sum=0;
        for(int i=0;i<k;i++) sum+=b[i];
        int res=0;
        if(sum==k) res++;
        for(int i=k;i<n-1;i++){
            sum-=b[i-k];
            sum+=b[i];
            if(sum==k) res++;
        }

        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}