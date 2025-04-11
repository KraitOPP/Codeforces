#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

int getParent(int n, vector<int> &parent){
    if(parent[n]==n) return n;

    return parent[n] = getParent(parent[n],parent);
}

bool dsu(int x, int y, vector<int> &parent, vector<int> &sizes) {
    x = getParent(x, parent);
    y = getParent(y, parent);
    if (x == y) return false;
    if (sizes[x] < sizes[y]) swap(x, y); 
    parent[y] = x;
    sizes[x] += sizes[y];
    return true;
}



signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> cows(n);
    for(int i=0;i<n;i++){
        cin>>cows[i];
        cows[i]--;
    }

    vector<vector<int>> worms;
    int mxwidth=0;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        worms.push_back({u,v,w});
        mxwidth=max(mxwidth,w);
    }
    int low=0,high=mxwidth+1;
    int res=0;
    while(low<=high){
        int mid = (low+high)/2;

        vector<int> sizes(n,1),parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<m;i++){
            if(worms[i][2]<=mid){
                dsu(worms[i][0],worms[i][1],parent,sizes);
            }
        }
        bool isPos=true;

        for(int i=0;i<n;i++){
            if(getParent(i,parent)!=getParent(cows[i],parent)){
                isPos=false;
                break;
            }
        }

        if(isPos){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;

    }

    if(res==mxwidth+1) cout<<-1<<endl;
    else cout<<res<<endl;

    return 0;
}