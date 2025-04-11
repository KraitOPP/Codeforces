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
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s.begin(),s.end(),[&](string a, string b){
        return (a+b)< b+a;
    });
    for(int i=0;i<n;i++) cout<<s[i];
    cout<<endl;
    return 0;
}