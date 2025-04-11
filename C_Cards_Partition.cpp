#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

void solve(int mx, int k, int n, int sum){
    for(int i=n;i>=1;i--){
        int d = (sum+k)-(sum+k)%i;
        d/=i;
        if(mx<=d && d*i>=sum){
            cout<<i<<endl;
            return;
        }
    }
}

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
        int sum=0,mx=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            mx=max(mx,a[i]);
        }
        solve(mx,k,n,sum);


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}