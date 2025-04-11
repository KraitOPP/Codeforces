4#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool isPos(vector<int> a,int n,double mid,int k){
    int cnt=0;
    if(mid==0) return true;
    for(int i=0;i<n;i++){
        cnt+=a[i]/mid;
    }
    return cnt>=k;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<setprecision(7);
    double s=0,e=1e8;
    double res=-1;
    for(int i=0;i<100;i++){
        double mid=s+(e-s)/2;
        if(isPos(a,n,mid,k)){
            res=mid;
            s=mid;
        }
        else e=mid;
    }

    cout<<res<<endl;

    return 0;
}