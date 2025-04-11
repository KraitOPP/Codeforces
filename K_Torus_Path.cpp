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
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            sum+=a[i][j];
        }
    }
    int mn=a[0][n-1];
    for(int i=0;i<n;i++) mn=min(mn, a[i][n-1-i]);
    
    cout<<sum-mn<<endl;
    return 0;
}