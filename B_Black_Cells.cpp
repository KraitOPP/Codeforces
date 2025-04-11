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

int solve(vi a, int n){
    int res=1;
    for(int i=1;i<n;i+=2){
        res=max(res,a[i]-a[i-1]);
    }

    return res;
}

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
        vi a(n);
        inp(a,n);
        int res=solve(a,n);
        if(n%2==0){
            cout<<res<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            vi tmp(a.begin(),a.end());
            if(i>0){
                tmp.insert(tmp.begin()+i-1, a[i]-1);
                res=min(res,solve(tmp, n+1));
                tmp.erase(tmp.begin()+i-1);
            }
            tmp.insert(tmp.begin()+i+1, a[i]+1);
            res=min(res,solve(tmp,n+1));
        }

        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}