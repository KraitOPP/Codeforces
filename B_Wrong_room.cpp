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
    int sc=0;
    vector<int> a(n);
    bool flg=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0 && a[i]>a[0]){
            flg=false;
        }
    }
    if(flg) cout<<"S"<<endl;
    else cout<<"N"<<endl;
    return 0;
}