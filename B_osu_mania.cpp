#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

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
        vector<int> ans;
        vector<vector<char>> a(n,vector<char>(4));
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++) cin>>a[i][j];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<4;j++){
                if(a[i][j]=='#') ans.push_back(j+1);
            }
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}       