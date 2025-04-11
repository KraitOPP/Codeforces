#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int tmp;
                cin>>tmp;
                a[j].push_back(tmp);
            }
        }
        for(int i=0;i<m;i++) sort(a[i].begin(),a[i].end());
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res+=a[i][j]*(j-(n-1-j));
            }
        }
        cout<<res<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}