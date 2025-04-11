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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
    string tmp;
    if(n<=k){
        while(tmp.size()<k) tmp+=s;
    }
    else tmp = s;
    for(int i=1;i<=k;i++){
        string rs = s.substr(0,i);
        while(rs.size()<k) rs+=rs;
        rs = rs.substr(0,k);
        if(rs < tmp) tmp=rs;
    }

    cout<<tmp<<endl;

    return 0;
}