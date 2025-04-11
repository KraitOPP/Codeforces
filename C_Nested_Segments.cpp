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
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(3));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1], a[i][2]=i;
    sort(a.begin(),a.end(),[&](vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    });
    
    int idx1=-1,idx2=-1,mxend=0;
    for(int i=0;i<n;i++){
        if(a[i][0] > mxend) idx1=-1;
        if(a[i][1] <= mxend){
            idx2=a[i][2];   
            break;
        }
        else if(mxend<a[i][1]){
            mxend=a[i][1];
            idx1=a[i][2];
        }
    }

    if(idx1==-1 || idx2==-1) cout<<-1<<" "<<-1<<endl;
    else cout<<idx2+1<<" "<<idx1+1<<endl;

    return 0;
}