#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
const int N=2000+100;
vector<int> parent(N),sz(N),up(N),down(N),lft(N),rght(N);

int dist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int par(int node){
    if(parent[node]==node) return node;

    return parent[node] = par(parent[node]);
}

void unio(int x, int y){
    x=par(x);
    y=par(y);
    if(x==y) return;
    if(sz[y] > sz[x]) swap(x,y);

    parent[y]=parent[x];
    sz[x]+=sz[y];
    up[x]=up[x] | up[y];
    down[x] = down[x] | down[y];
    rght[x] = rght[x] | rght[y];
    lft[x] = lft[x] | lft[y];
}


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> a(k,vector<int>(3));
    for(int i=0;i<k;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }

    for(int i=0;i<k;i++){
        parent[i]=i;
        sz[i]=1;
        up[i]=down[i]=0;
        rght[i]=lft[i]=0;
        if(a[i][0] <= a[i][2]){
            //left
            lft[i]=1;
        }
        if(a[i][1] <= a[i][2]){
            //down
            down[i]=1;
        }
        if((n-a[i][0]) <= a[i][2]){
            //right
            rght[i]=1;
        }
        if((m-a[i][1]) <= a[i][2]){
            //up
            up[i]=1;
        }
    }

    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(dist(a[i][0],a[i][1],a[j][0],a[j][1]) <= (a[i][2]+a[j][2])*(a[i][2]+a[j][2])){
                unio(i,j);
            }
        }
    }

    bool flg=true;

    for(int i=0;i<k;i++){
        int pare  = par(i);
        if((up[pare] || lft[pare]) && (down[pare] || rght[pare])){
            flg=false;
            break;
        }
    }

    if(flg) cout<<"S"<<endl;
    else cout<<"N"<<endl;

    return 0;
}