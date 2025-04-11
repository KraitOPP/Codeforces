#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

bool solve(vector<vector<int>> &a, int n, int m){
    if(n==1 && m==1) return false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m/2;j++){
            swap(a[i][j],a[i][m-1-j]);
        }
    }
    if(m%2==1){
        for(int i=0;i<n/2;i++) swap(a[i][m/2],a[n-1-i][m/2]);
        if(n%2==1){
            if(n==1){
                swap(a[0][m/2],a[0][0]);
                return true;
            }
            swap(a[n/2][m/2],a[0][m/2]);
        }
    }
    return true;
}

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
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        if(solve(a,n,m)){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++) cout<<a[i][j]<<" ";
                cout<<endl;
            }
        }
        else cout<<-1<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}