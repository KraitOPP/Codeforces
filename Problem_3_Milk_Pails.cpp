#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int N = 101,inf = 1e9;
int dis[N][N];


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,y,k,m;
    cin>>x>>y>>k>>m;
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            dis[i][j]=inf;   
        }
    }
    queue<vector<int>> q;
    q.push({0,0,0});
    while(!q.empty()){
        vector<int> v = q.front();
        q.pop();
        int i = v[0],j = v[1], d = v[2];
        dis[i][j]=d;
        int xpour = min(max(j-i,0ll),x-i);
        int ypour = min(max(i-j,0ll),y-j);
        vector<int> dx = {i,0,x,i,i+xpour,i-ypour};
        vector<int> dy = {0,j,j,y,j-xpour,j+ypour};
        for(int i=0;i<6;i++){
            int nx = dx[i];
            int ny = dy[i];
            if(d+1>k || dis[nx][ny]!=inf) continue;
            q.push({nx,ny,d+1});
        }
    }

    int res=inf;
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(dis[i][j]!=inf){
                res=min(res,abs(i+j-m));
            }
        }
    }
    cout<<res<<endl;

    return 0;
}