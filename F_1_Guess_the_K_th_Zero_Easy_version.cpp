#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    int n,t;
    cin>>n>>t;
    int k;
    cin>>k;

    int s=1,e=n;
    int res=-1;
    while(s<=e){
        int sm;
        int mid=s+(e-s)/2;
        cout<<"? "<<1<<" "<<mid<<endl;
        cin>>sm;
        if(sm<=(mid-k)){
            res=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    cout<<"! "<<res<<endl;

    return 0;
}