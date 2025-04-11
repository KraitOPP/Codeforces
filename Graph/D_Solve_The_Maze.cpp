#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
int n,m;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

void floodTraversal(int i, int j, vector<vector<char>> &a, vector<vector<int>> &vis){
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(a[i][j]=='#' || vis[i][j]) return;
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int nx = i+dx[k];
        int ny = j+dy[k];

        floodTraversal(nx,ny,a,vis);
    }
}


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        cin>>n>>m;
        vector<vector<char>> a(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='B'){
                    for(int k=0;k<4;k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<m){
                            if(a[nx][ny]=='G'){
                                flag=false;
                                break;
                            }
                            if(a[nx][ny]=='.'){
                                a[nx][ny]='#';
                            }
                        }  
                    }
                }
                if(flag==false) break;
            }
            if(flag==false) break;
        }

        if(flag==false){
            cout<<"NO"<<endl;
        }
        else{
            floodTraversal(n-1,m-1,a,vis);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(a[i][j]=='G' && !vis[i][j]){
                        flag=false;
                        break;
                    }
                }
                if(flag==false) break;
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }



        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}