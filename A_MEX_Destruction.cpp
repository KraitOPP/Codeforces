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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0) cnt++;
        }
        int start=0, end=n-1;
        while(start<n && a[start]==0) start++;
        while(end>=0 && a[end]==0) end--;
        int lft = cnt-start-(n-1-end);
        if(cnt==n) cout<<0<<endl;
        else if(cnt==0 || lft==0) cout<<1<<endl;
        else if(start==end) cout<<1<<endl;
        else cout<<2<<endl; 
    }
    return 0;
}