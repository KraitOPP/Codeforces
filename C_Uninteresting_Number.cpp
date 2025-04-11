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
        auto begin = chrono::high_resolution_clock::now();
        string s;
        cin>>s;
        int n=s.length();
        int n1=0,n2=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='2') n1++;
            else if(s[i]=='3') n2++;
            sum+=s[i]-'0';
        }
        int pos=0;
        for(int i=0;i<=min(n1,8LL);i++){
            for(int j=0;j<=min(n2,8LL);j++){
                int x = i*2+j*6;
                if((sum+x)%9==0){
                    cout<<"YES"<<endl;
                    pos=1;
                    break;
                }
            }
            if(pos==1) break;
        }
        if(pos==0) cout<<"NO"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}