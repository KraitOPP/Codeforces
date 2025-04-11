#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        map<int,vector<int>> row,col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                row[a[i][j]].push_back(i);
                col[a[i][j]].push_back(j);
            }
        }
        int res=0;
        for(auto itr:row){
            sort(itr.second.begin(),itr.second.end());
            for(int i=0;i<itr.second.size();i++){
                res+=itr.second[i]*(2*i-itr.second.size()+1);
            }

        }
        for(auto itr:col){
            sort(itr.second.begin(),itr.second.end());
            for(int i=0;i<itr.second.size();i++){
                res+=itr.second[i]*(2*i-itr.second.size()+1);
            }
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}