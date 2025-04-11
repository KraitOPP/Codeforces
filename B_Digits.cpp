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
        int n,d;
        cin>>n>>d;
        vi res;
        res.push_back(1);
        if(n>=3 || d%3==0) res.push_back(3);
        if(d==5) res.push_back(5);
        if(d==7 || n>=3) res.push_back(7);
        if(n>=9) res.push_back(9);
        else{
            int fact=d;
            for(int i=2;i<=n;i++) fact*=i;
            if(fact%9==0) res.push_back(9);
        }
        for(auto itr: res) cout<<itr<<" ";
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}