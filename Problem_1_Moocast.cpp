#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

int calcdist(int x1, int x2, int y1, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> cord(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        cord[i] = {x,y};
    }
    vector<int> dist(n,INT_MAX-1);
    int res=0;
    dist[0]=0;
    for(int i=0;i<n;i++){
        
    }

    cout<<res<<endl;

    return 0;
}