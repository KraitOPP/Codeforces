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
        bool flg=false;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                flg=true;
                cout<<s[i]<<s[i]<<endl;
                break;
            }
            if(i>1){
                int j=i-2;
                if(s[j]!=s[j+1] && s[j]!=s[j+2] && s[j+1]!=s[j+2]){
                    flg=true;
                    cout<<s[j]<<s[j+1]<<s[j+2]<<endl;
                    break;
                }
            }
        }
        if(!flg) cout<<"-1"<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}