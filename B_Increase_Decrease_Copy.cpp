#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int b[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n+1;i++) cin>>b[i];

        int ans=0;
        int mn=INT_MAX;
        int num=b[n];
        for(int i=0;i<n;i++){
            ans+=abs(a[i]-b[i]);
            if(a[i]>=b[i] && (num<=a[i] && num>=b[i])) mn=0;
            if(a[i]<=b[i] && (num>=a[i] && num<=b[i])) mn=0;
            mn = min(mn,min(abs(a[i]-num),abs(b[i]-num)));
        }
        cout<<ans+mn+1<<endl;
    }
    return 0;
}