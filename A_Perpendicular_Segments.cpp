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
        int x,y,k;
        cin>>x>>y>>k;
        if(x<y){
            cout<<"0 0 "<<x<<" "<<x<<endl;
            cout<<"0 "<<x<<" "<<x<<" "<<0<<endl;
        }
        else{
            cout<<"0 0 "<<y<<" "<<y<<endl;
            cout<<"0 "<<y<<" "<<y<<" "<<0<<endl;
        }



        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}