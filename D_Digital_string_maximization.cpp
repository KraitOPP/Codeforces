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
        for(int i=0;i<9;i++){
            for(int j=1;j<n;j++){
                int x=s[j]-'0';
                int y=s[j-1]-'0';
                if(x>y+1){
                    char tmp = s[j-1];
                    x--;
                    s[j-1]=x+'0';
                    s[j]=tmp;
                }
            }
        }
        cout<<s<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}