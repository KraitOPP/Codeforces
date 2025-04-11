#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool isPos(vector<int> a,int n,int mid,int k){
    int curr=0;
    for(int i=n/2;i<n;i++){
        curr+=(mid-a[i]);
        if(curr>k) return false;
    }
    return true;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vi a(n);
    inp(a,n);
    sort(a.begin(),a.end());

    int s=a[n/2],e=2*1e9,res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPos(a,n,mid,k)){
            res=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    cout<<res<<endl;
    return 0;
}