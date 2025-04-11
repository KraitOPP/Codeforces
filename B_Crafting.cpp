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
        int n;
        cin>>n;
        vi a(n), b(n);
        inp(a,n);
        inp(b,n);
        int cnt=0, mn=INT_MAX, mx=0;
        for(int i=0;i<n;i++){
            if(a[i]-b[i] < 0){
                cnt++;
                mx=b[i]-a[i];
            }
            else mn=min(mn, a[i]-b[i]);
        }
        
        if(cnt>1 || mx>mn) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   