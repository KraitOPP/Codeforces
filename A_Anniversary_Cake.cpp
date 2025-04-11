#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
#define pii pair<int,int>
const int inf = 1e18,mod=1e9+7;


signed main(){ 
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
    int w,h,x1,y1,x2,y2;
    cin>>w>>h>>x1>>y1>>x2>>y2;
    if(x1==x2){
        int sx = 0, sy = y2;
        int ex = w, ey = y1;

        cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
    }
    else{
        int sx = x1, sy = 0;
        int ex = x2, ey = h;

        cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
    }
    return 0;
}