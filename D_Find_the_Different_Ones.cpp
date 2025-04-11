#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve(){
    int n;
    cin>>n;
    int a[n];

    for(int i = 0;i<n;i++) cin>>a[i];

    int pre[n];
    pre[0] = -1;

    for(int i = 1;i<n;i++){
        if(a[i] != a[i-1]){
            pre[i] = i;
        }else{
            pre[i] = pre[i-1];
        }
    }
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        int z=l;
        l--;r--;
        int i=-1,j=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(pre[mid] >=z){
                i=pre[mid];j=mid+1;
                break;
            }
            l = mid+1;
        }
        cout<<i<<" "<<j<<endl;
    }
    cout<<endl;
}

signed main(){
       
        int t;
        cin>>t;
        int mod = 1e9+7;
        while(t--){
            solve();
        }
}