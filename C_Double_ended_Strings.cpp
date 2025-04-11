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
        string a,b;
        cin>>a>>b;
        int mxlen = 0;
        for(int i=0;i<a.length();i++){
            int j=i;
            for(int k=0;k<b.length();k++){
                if(j<a.length() && a[j]==b[k]){
                    j++;
                    mxlen = max(mxlen,j-i);
                }
                else j=i;
            }
        }
        for(int i=0;i<b.length();i++){
            int j=i;
            for(int k=0;k<a.length();k++){
                if(j<b.length() && a[k]==b[j]){
                    j++;
                    mxlen = max(mxlen,j-i);
                }
                else j=i;
            }
        }

        cout<<a.length()+b.length()-2*mxlen<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}