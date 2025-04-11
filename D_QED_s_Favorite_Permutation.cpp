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
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        int mx=0,cnt=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
            a[i]=mx;
        }
        string s;
        cin>>s;
        for(int i=0;i<n-1;i++){
            if(s[i]=='L' && s[i+1]=='R'){
                if(a[i] > (i+1)) cnt++;
            }
        }


        while(q--){
            int idx;
            cin>>idx;
            if(s[idx-1]=='R'){
                s[idx-1]='L';
                if(idx<n && s[idx]=='R'){
                    if(a[idx-1] > idx) cnt++;
                }
                if(idx-2>=0 && s[idx-2]=='L'){
                    if(a[idx-2] > idx-1) cnt--;
                }
            }
            else{
                s[idx-1]='R';
                if(idx<n && s[idx]=='R'){
                    if(a[idx-1] > idx) cnt--;
                }
                if(idx-2>=0 && s[idx-2]=='L'){
                    if(a[idx-2] > idx-1) cnt++;
                }
            }
            if(cnt==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }


    }
    return 0;
}