#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

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
        vector<int> a(n);
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mn=min(mn,a[i]);
        }
        int cnt=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(a[i]==mn) cnt++;
            if((a[i]%mn)!=0) flag=true;
        }
        if(cnt==1 || flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}