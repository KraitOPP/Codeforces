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
    int q;
    cin>>s;
    cin>>q;
    int n=s.length();
    vector<vector<int>> pre(n,vector<int>(26,0));
    pre[0][s[0]-'a']=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++){
            pre[i][j]=pre[i-1][j];
        }
        pre[i][s[i]-'a']+=1;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int cnt=0;
        for(int i=0;i<26;i++){
            int x =(l-1>=0) ? pre[r][i]-pre[l-1][i]: pre[r][i];
            cnt+=x>0;
        }
        if(cnt>2 || l==r || s[l]!=s[r]){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}