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
        vector<vector<int>> b(n);
        vector<vector<int>> pre(n);
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            b[a[i]-1].push_back(tmp);
        }
        for(int i=0;i<n;i++){
            sort(b[i].begin(),b[i].end(),greater<int>());
        }
        for(int i=0;i<n;i++){
            pre[i].push_back(0);
            for(int j=0;j<b[i].size();j++){
                pre[i].push_back(pre[i].back()+b[i][j]);
            }
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=1;j<=b[i].size();j++){
                ans[j-1] += pre[i][b[i].size()/j*j];
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