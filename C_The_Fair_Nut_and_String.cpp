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
    string s;
    cin>>s;
    int n=s.length();
    stack<pair<char,int>> st;
    int res=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            res=(res+1)%mod;
            while(!st.empty() && st.top().first!='b'){
                st.pop();
            }
            if(!st.empty()){
                res=(res+st.top().second)%mod;
            }
        }
        else if(s[i]=='b'){
            st.push({s[i],res});
        }
    }
    cout<<res<<endl;
    return 0;
}