#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool isPos2(int w, int x, int y, int z, int t){
    int rq=0;
    if(w%z==0){
        rq = (w/z-1)*(z*x+y) + z*x;
    }
    else{
        rq = (w/z)*(z*x+y) + (w%z)*x;
    }

    return rq<=t;
}

bool isPos(vector<vector<int>> a,int n,int mid,int m){
    int cnt=0;
    for(int i=0;i<m;i++){
        int s=0,e=1e9,c=0;
        while(s<=e){
            int md = s+(e-s)/2;
            if(isPos2(md,a[i][0],a[i][1],a[i][2], mid)){
                c=md;
                s=md+1;
            }
            else e=md-1;
        }
        cnt+=c;
    }

    return cnt>=n;
}

int ballons(int x, int y, int z, int t){
    int rq = (t/(z*x+y))*z;
    if(t%(z*x+y)!=0){
        if((t%(z*x+y))/x >= z){
            rq+=z;
        }
        else rq+=(t%(z*x+y))/x;
    }

    return rq;
}


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(m,vector<int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    int s=0,e=1e9;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPos(a,n,mid,m)){
            res=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    cout<<res<<endl;
    for(int i=0;i<m;i++){
        int ans = ballons(a[i][0],a[i][1],a[i][2],res);
        cout<<ans<<" ";
    }
    cout<<endl;

    return 0;
}