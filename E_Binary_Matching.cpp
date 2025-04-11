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
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        string s;
        cin>>s;
        int c1=n,c2=n;
        if(s[0]==s[n-1]) cout<<0<<endl;
        else{
            for(int i=1;i<n;i++){
                if(s[i]=='0'){
                    c1=i;
                    break;
                }
            }
            for(int i=n-2;i>=0;i--){
                if(s[i]=='0'){
                    c2=n-i-1;
                    break;
                }
            }
            cout<<min(min(c1,c2),2LL)<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}