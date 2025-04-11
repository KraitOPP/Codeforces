#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
int n;

void floodTraversal(vector<vector<char>> &a, vector<vector<bool>> &vis, int i, int j, int xmin, int xmax, int ymin, int ymax, char col){
    if(i<xmin || i>xmax || j<ymin || j>ymax) return;
    if(vis[i][j] || a[i][j]!=col) return;
    vis[i][j]=true;
    floodTraversal(a,vis,i+1,j,xmin,xmax,ymin,ymax,col);
    floodTraversal(a,vis,i-1,j,xmin,xmax,ymin,ymax,col);
    floodTraversal(a,vis,i,j+1,xmin,xmax,ymin,ymax,col);
    floodTraversal(a,vis,i,j-1,xmin,xmax,ymin,ymax,col);
}

bool checkContains(int x1min, int x1max, int y1min, int y1max, int x2min, int x2max, int y2min, int y2max){
    if(x1min>=x2min && x1max<=x2max && y1min>=y2min && y1max<=y2max) return true;
    return false;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("where.in", "r", stdin);
    cin>>n;
    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }

    vector<vector<int>> res;
    vector<vector<bool>> vis(n,vector<bool>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=i;k<n;k++){
                for(int l=j;l<n;l++){
                    vector<int> comp(26,0);
                    fill(vis.begin(),vis.end(), vector<bool>(n));
                    for(int m=i;m<=k;m++){
                        for(int n=j;n<=l;n++){
                            if(!vis[m][n]){
                                floodTraversal(a,vis,m,n,i,k,j,l,a[m][n]);
                                comp[a[m][n]-'A']++;
                            }
                        }
                    }
                    int one=0;
                    int more=0;
                    for(int i=0;i<26;i++){
                        if(comp[i]==1) one++;
                        if(comp[i]>1) more++;
                    }

                    if(one==1 && more==1){
                        res.push_back({i,k,j,l});
                    }
                }
            }
        }
    }

    int ans=0;
    for(int i=0;i<res.size();i++){
        bool contains=false;
        for(int j=0;j<res.size();j++){
            if(i==j) continue;
            if(checkContains(res[i][0],res[i][1],res[i][2],res[i][3],res[j][0],res[j][1],res[j][2],res[j][3])){
                contains=true;
            }
        }
        if(contains==false) ans++;
    }
    freopen("where.out", "w", stdout);
    cout<<ans<<endl;

    return 0;
}