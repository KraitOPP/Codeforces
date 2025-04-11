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
        int n;
        cin>>n;
        string a;
        cin>>a;
        if(a[0]=='1' || a[n-1]=='1') cout<<"YES"<<endl;
        else{
            bool flg=0;
            for(int i=1;i<n;i++){
                if(a[i]=='1' && a[i-1]=='1') flg=true;
            }
            if(flg) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}