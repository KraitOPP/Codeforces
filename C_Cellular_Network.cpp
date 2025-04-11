#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool isPos(vector<int> a, vector<int> t, int n, int m, int mid){
    int diff=0,j=0;
    for(int i=0;i<n;i++){
        while(j<m && (abs(a[i]-t[j])>mid)) j++;
        if(j==m) return false;
    }

    return true;
}


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> a(n),t(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>t[i];
    
    int s=0,e=2*1e9+100;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPos(a,t,n,m,mid)){
            res=mid;
            e=mid-1;
        }
        else s=mid+1;
    }

    cout<<res<<endl;

    return 0;
}