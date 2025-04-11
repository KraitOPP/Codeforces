#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int n;
    string s;
    cin>>n>>s;
    int res=inf;
    vector<int> offX(n+1,0),offY(n+1,0);
    for(int i=0;i<n;i++){
        offY[i+1]=offY[i];
        offX[i+1]=offX[i];
        if(s[i]=='U'){
            offY[i+1]+=1;
        }
        else if(s[i]=='D'){
            offY[i+1]-=1;
        }
        else if(s[i]=='L'){
            offX[i+1]-=1;
        }
        else if(s[i]=='R'){
            offX[i+1]+=1;
        }
    }

    for(int i=1;i<=n;i++){
        int s=0,e=1e9;
        while(s<=e){
            int mid=s+(e-s)/2;
            int nwx=x1 + offX[i]+mid*offX[n];
            int nwy=y1 + offY[i]+mid*offY[n];
            int diff = abs(x2-nwx) + abs(y2-nwy);
            int days = i+mid*n;
            if(diff<=days){
                res=min(res,days);
                e=mid-1;
            }
            else s=mid+1;
        }
    }

    if(res==inf){
        cout<<-1<<endl;
    }
    else cout<<res<<endl;
    return 0;
}