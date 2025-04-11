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
        int n,m;
        cin>>n>>m;
        vector<vector<char>> a(n,vector<char>(m));
        bool flg=true;
        vector<int> r1,r2;
        for(int i=0;i<n;i++){
            int cnt1=0;
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='U' || a[i][j]=='D') cnt1++;
            }
            if(cnt1%2!=0) flg=false;
            r1.push_back(cnt1);
        }
        for(int i=0;i<m;i++){
            int cnt1=0;
            for(int j=0;j<n;j++){
                if(a[j][i]=='L' || a[j][i]=='R') cnt1++;
            }
            if(cnt1%2!=0) flg=false;
            r2.push_back(cnt1);
        }
        if(flg){
            for(int i=0;i<n-1;i++){
                int cnt1=r1[i]/2;
                for(int j=0;j<m;j++){
                    if(a[i][j]=='U'){
                        if(cnt1>0){
                            a[i][j]='W';
                            a[i+1][j]='B';
                            r1[i+1]--;
                            cnt1--;
                        }
                        else{
                            a[i][j]='B';
                            a[i+1][j]='W';
                        }
                    }
                }
            }
            for(int i=0;i<m-1;i++){
                int cnt1=r2[i]/2;
                for(int j=0;j<n;j++){
                    if(a[j][i]=='L'){
                        if(cnt1>0){
                            a[j][i]='W';
                            a[j][i+1]='B';
                            r2[i+1]--;
                            cnt1--;
                        }
                        else{
                            a[j][i]='B';
                            a[j][i+1]='W';
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<a[i][j];
                }
                cout<<endl;
            }
        }
        else cout<<"-1"<<endl;
    }
    return 0;
}