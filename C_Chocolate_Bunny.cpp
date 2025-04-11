#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    int n;
    cin>>n;
    vector<int> a(n,-1);
    int mx=1;
    for(int i=1;i<n;i++){
        int p1,p2;
        cout<<"? "<<mx<<" "<<i+1<<endl;
        cin>>p1;
        cout<<"? "<<i+1<<" "<<mx<<endl;
        cin>>p2;
        if(p1>p2){
            a[mx-1] = p1;
            mx=i+1;
        }
        else{
            a[i] = p2;
        }
    }

    cout<<"! ";
    for(int i=0;i<n;i++){
        if(a[i]==-1) a[i]=n;
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}