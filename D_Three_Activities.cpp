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
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> a(3,vector<pair<int,int>>(n));
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                int tmp;
                cin>>tmp;
                a[i].push_back({tmp,j});
            }
            sort(a[i].begin(),a[i].end(),greater<pair<int,int>>());
        }
        int ans=-1;
        for(int i=0;i<3;i++){
            int n1=a[0][i].first,idx1=a[0][i].second;
            for(int j=0;j<3;j++){
                int n2=a[1][j].first,idx2=a[1][j].second;
                for(int k=0;k<3;k++){
                    int n3=a[2][k].first,idx3=a[2][k].second;
                    if(idx1!=idx2 && idx1!=idx3 && idx2!=idx3){
                        ans=max(ans,n1+n2+n3);
                    }
                }
            }
        }
        cout<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}