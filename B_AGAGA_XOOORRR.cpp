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
        vector<int> a(n),pre(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i==0){
                pre[i]=a[i];
            }
            else pre[i]=pre[i-1]^a[i];
        }

        if(pre[n-1]==0) cout<<"YES"<<endl;
        else{
            bool flag=false;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(pre[i]==(pre[i]^pre[j]) && pre[i]==(pre[j]^pre[n-1])){
                        flag = true;
                    }
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}