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
        string s;
        cin>>s;
        int n=s.length();
        string mx = string(n,'0');
        int start=1,end=n;
        for(int i=0;i<n;i++){
            string b=s;
            for(int j=i;j<n;j++){
                if(b[j-i]==s[j]){
                    b[j-i]='0';
                }
                else{
                    b[j-i]='1';
                }
                if(b>mx){
                    mx=b;
                    start=i+1, end=j+1;
                }
            }
        }

        cout<<1<<" "<<n<<" "<<start<<" "<<end<<endl;
    }
    return 0;
}