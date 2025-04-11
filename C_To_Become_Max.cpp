#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool isPos(vi a,int n,int k,int mid){
    for(int i=0;i<n;i++){
        int curr=mid, cnt=k;
        for(int j=i;j<=n;j++){
            if(a[j]>=curr) return true;
            cnt-=curr-a[j];
            if(cnt<0) break;
            curr--;
        }
        if(cnt>0) return true;
    }

    return false;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,k;
        cin>>n>>k;
        vi a(n+1);
        inp(a,n);
        a[n]=INT_MIN;
        int s=1, e=1e9, res=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPos(a,n,k,mid)){
                res=mid;
                s=mid+1;
            }
            else e=mid-1;
        }

        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}