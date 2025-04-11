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
        int n;
        string s;
        cin>>n>>s;
        int st=1;
        int cnts=0, cntp=0, cntd=0;
        for(int i=0;i<n;i++){
            if(s[i]=='p') cntp++;
            else if(s[i]=='s') cnts++;
            else cntd++;
        }

        if(cnts==n || cntp==n || cntd==n) cout<<"YES"<<endl;
        else if(cnts==0 || cntp==0) cout<<"YES"<<endl;
        else if((cnts==1 && s[0]=='s') || (cntp==1 && s[n-1]=='p')) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}