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
        int n,m;
        cin>>n>>m;
        vector<int> a(n+1,0),b(m+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        sort(a.begin(),a.end());
        int start=1;
        int res=0;
        for(int i=n;i>=1;i--){
            if(a[i]>=start){
                res+=b[start];
                start++;
            }
            else res+=b[a[i]];
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}