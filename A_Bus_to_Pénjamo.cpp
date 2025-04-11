#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,r;
        cin>>n>>r;
        vector<int> a(n);
        int res=0,cnt=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>=2){
                res+=2*(a[i]/2);
                r-=a[i]/2;
            }
            a[i]=a[i]%2;
            if(a[i]) cnt++;
        }

        if(r>=cnt) cout<<cnt+res<<endl;
        else{
            cout<<r-(cnt-r)+res<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}