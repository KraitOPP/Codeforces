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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        // int i=0;
        // for(i=0;i<n;i++){
        //     if((a[i]-a[0]) >= k) break;
        // }
        // int res=i;
        // int x = 0;
        // for(int j=i;j<n;j++){
        //     while((a[j]-a[x])>=k) x++;

        //     res=max(res,(j-x+1));
        // }
        int res=0;
        int i=0,j=0;
        for(j=0;j<n;j++){
            while(i<n && (a[j]-a[i])>=k) i++;

            if(j>0 && a[j]-a[j-1]>1) i=j;
            res=max(res,(j-i+1));
        }

        cout<<res<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}