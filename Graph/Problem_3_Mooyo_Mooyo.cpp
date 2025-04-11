#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7,N=100+10;
int n,k;
vector<vector<char>> a(N,vector<char>(10));
vector<vector<bool>> vis(N,vector<bool>(10));
vector<pair<int,int>> arr;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

int floodTraversal(int i, int j, vector<vector<char>> &a, vector<vector<bool>> &vis, char col){
    if(i<0 || i>=n || j<0 || j>=10) return 0;
    if(vis[i][j] || a[i][j]!=col) return 0;
    vis[i][j]=true;
    arr.push_back({i,j});
    return 1+floodTraversal(i+1,j,a,vis,col)+floodTraversal(i-1,j,a,vis,col)+floodTraversal(i,j+1,a,vis,col)+floodTraversal(i,j-1,a,vis,col);
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("mooyomooyo.in", "r", stdin);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cin>>a[i][j];
        }
    }

    bool changed=true;
    while(changed){
        changed=false;
        fill(vis.begin(),vis.end(),vector<bool>(10,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                if(!vis[i][j] && a[i][j]!='0'){
                    arr.clear();
                    char col=a[i][j];
                    int cnt = floodTraversal(i,j,a,vis,col);
                    if(cnt>=k){
                        changed=true;
                        for(int k=0;k<arr.size();k++){
                            a[arr[k].first][arr[k].second]='0';
                        }
                    }
                }
            }   
        }
        for(int i=0;i<10;i++){
            vector<int> grav;
            for(int j=0;j<n;j++){
                if(a[j][i]!='0'){
                    grav.push_back(a[j][i]);
                }
            }
            int emptyRows = n - grav.size();
            for (int j = 0; j < emptyRows; j++) {
                a[j][i] = '0'; 
            }
            for (int j = emptyRows; j < n; j++) {
                a[j][i] = grav[j - emptyRows];
            }
        }
    }

    freopen("mooyomooyo.out", "w", stdout);
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }


    return 0;
}