#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
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
        vi a(n);
        inp(a,n);
        sort(a.begin(),a.end());
        vi pre(n);
        for(int i=0;i<n;i++){
            if(i==0) pre[i]=a[i];
            else pre[i]=pre[i-1]+a[i];
        }
        vi dp(n,0);
        for(int i=0;i<n;i++){
            int res=pre[i];
            int free=(i+1)/(k+1);
            int j=i-k;
            if(j>=0){
                res-=a[j];
                if(j>0) res+=dp[j-1]-pre[j-1];
            }
            cout<<res<<" ";
            dp[i]=res;
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}