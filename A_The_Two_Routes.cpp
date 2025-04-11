#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int N=400+20;
vector<int> adj[N];
int res=INT_MAX;

void bfs(int n){
    queue<int> q;
    q.push(0);
    vector<int> dist(n,1e9);
    dist[0]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto neigh:adj[u]){
            if(dist[neigh] > dist[u]+1){
                dist[neigh]=dist[u]+1;
                q.push(neigh);
            }
        }
    }

    res=dist[n-1] !=1e9 ? dist[n-1] : -1;
}



signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<set<int>> st(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        st[u-1].insert(v-1);
        st[v-1].insert(u-1);
    }

    if(st[0].find(n-1)==st[0].end()){
        for(int i=0;i<n;i++){
            for(auto neigh:st[i]){
                adj[i].push_back(neigh);
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(st[i].find(j)==st[i].end() && st[j].find(i)==st[j].end()){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }

    bfs(n);

    cout<<res<<endl;

    return 0;
}