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
        int n;
        cin>>n;
        vector<vector<int>> a(n, vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1];
            a[i][2] = i;
        }
        sort(a.begin(), a.end(), [&](vi x, vi y){
            if(x[0]==y[0]) return x[1]<y[1];
            return x[0]<y[0];
        });
        bool flg=false;
        vector<int> res(n,0);
        int prvend=a[0][1];
        res[a[0][2]]=1;
        for(int i=1;i<n;i++){
            if(a[i][0]>prvend){
                flg=true;
                res[a[i][2]]=2;
            }   
            else{
                res[a[i][2]]=1;
                prvend=max(a[i][1],prvend);
            }
        }

        if(flg){
            for(int i=0;i<n;i++) cout<<res[i]<<" ";
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }

    }
    return 0;
}