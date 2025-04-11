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

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vi res(1e6+1,0);
    vector<vector<int>> a(2024, vector<int>(3000,0));
    int currcol=2, currrow=0, prvele=1;
    for(int i=1;i<=2023;i++){
        int currele = currrow+prvele;
        prvele=currele;
        if(currele>1e6) break;
        int col=currcol;
        int j=1;
        while(currele<=1e6 && j<3000){
            a[i][j] = currele*currele+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            res[currele]=a[i][j];
            currele+=col;
            col++;
            j++;
        }
        currrow++;
        currcol++;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        cout<<res[n]<<endl;
    }
    return 0;
}   