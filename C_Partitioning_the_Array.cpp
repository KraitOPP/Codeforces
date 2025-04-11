#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool chck(vector<int> &a, int n, int k){
    int mxgc=0;
    for(int j=0;j+k<n;j++){
        mxgc=__gcd(mxgc,abs(a[j]-a[j+k]));
        if(mxgc==1) return false;
    }

    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int res=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i!=0) continue;
        if(n/i == i){
            if(chck(a,n,i)) res+=1;
        }
        else{
            if(chck(a,n,i)) res+=1;
            if(chck(a,n,n/i)) res+=1;
        }


    }

    cout<<res<<endl;

}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();  
        solve();
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}