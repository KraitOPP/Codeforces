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
        int n,k;
        cin>>n>>k;
        string s,t;
        cin>>s>>t;
        vi freq(26,0);
        bool flg=true;
        for(int i=0;i<n;i++) freq[s[i]-'a']++;
        for(int i=0;i<n;i++) freq[t[i]-'a']--;
        for(int i=0;i<26;i++){
            if(freq[i]<0 || freq[i]>0) flg=false;
        }
        if(!flg) cout<<"NO"<<endl;
        else if(n>(2*k-1) || s==t) cout<<"YES"<<endl;
        else {
            bool f=true;
            for(int i=0;i<26;i++) freq[i]=0;
            for(int i=0;i<n;i++){
                if(i>=k || i<n-k){
                    freq[s[i]-'a']++;
                    freq[t[i]-'a']--;
                }
                else if(s[i]!=t[i]){
                    f=false;
                }
            }
            for(int i=0;i<26;i++){
                if(freq[i]!=0) f=false;
            }
            if(f) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

    }
    return 0;
}