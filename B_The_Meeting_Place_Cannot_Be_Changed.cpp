#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool isPos(vector<int> x,vector<int> v,double mid,int n){
    double lft=-inf,rght=inf;
    for(int i=0;i<n;i++){
        lft=max(lft,x[i]-v[i]*mid);
        rght=min(rght,x[i]+v[i]*mid);
    }
    return lft<=rght;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> x(n),v(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>v[i];

    double s=0,e=1e10;
    double res=-1;
    cout<<fixed<<setprecision(7);
    for(int i=0;i<100;i++){
        double mid = s+(e-s)/2;
        if(isPos(x,v,mid,n)){
            res=mid;
            e=mid;
        }
        else s=mid;
    }

    cout<<res<<endl;

    return 0;
}