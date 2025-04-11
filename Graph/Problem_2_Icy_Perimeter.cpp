#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7,N=1e6+100;
int n;
vector<vector<int>> components(N,vector<int>(5,-1));
vector<int> dx({-1,1,0,0}),dy({0,0,-1,1});

void dfs(int i,int j,vector<vector<char>> &a,vector<vector<int>> &vis, int comp){

    components[comp][0]=min(i,components[comp][0]);
    components[comp][1]=max(i,components[comp][1]);
    components[comp][2]=min(j,components[comp][2]);
    components[comp][3]=max(j,components[comp][3]);
    components[comp][4]++;

    vis[i][j]=1;
    if(i-1>=0 && a[i-1][j]=='#' && !vis[i-1][j]) dfs(i-1,j,a,vis,comp);
    if(i+1<n && a[i+1][j]=='#' && !vis[i+1][j]) dfs(i+1,j,a,vis,comp);
    if(j-1>=0 && a[i][j-1]=='#' && !vis[i][j-1]) dfs(i,j-1,a,vis,comp);
    if(j+1<n && a[i][j+1]=='#' && !vis[i][j+1]) dfs(i,j+1,a,vis,comp);
}

int calculatePerimeter(int x, int y, vector<vector<char>> &a){
    int perim=0;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || a[nx][ny]=='.') perim++;
    }

    return perim;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(n,0));
    int comp=0;
    int resarea=0,resperim=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && a[i][j]=='#'){
                components[comp][0]=inf;
                components[comp][1]=-1;
                components[comp][2]=inf;
                components[comp][3]=-1;
                components[comp][4]=0;
                dfs(i,j,a,vis,comp);
                int area = components[comp][4];
                int perimeter = 0;
                for(int i=components[comp][0];i<=components[comp][1];i++){
                    for(int j=components[comp][2];j<=components[comp][3];j++){
                        if(a[i][j]=='#') perimeter+=calculatePerimeter(i,j,a);
                    }
                }
                if(area>resarea) resarea=area, resperim=perimeter;
                else if(area==resarea){
                    resperim=min(resperim,perimeter);
                }
                comp++;
            }
        }
    }

    cout<<resarea<<" "<<resperim<<endl;

    return 0;
}