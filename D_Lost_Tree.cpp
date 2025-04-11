#include <bits/stdc++.h>
using namespace std;

void dfs(vector<set<int>> &adj, int node, int par) {
    if (par != -1) {
        cout << node << " " << par << endl;
    }
    for (auto neigh : adj[node]) {
        if (par != neigh) {
            dfs(adj, neigh, node);
        }
    }
}

int main() {
    int n;
    cin >> n;

    queue<int> q1,q2;
    vector<set<int>> adj(n+1);
    cout<<"? 1"<<endl;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==0) continue;
        if(x==1){
            adj[1].insert(i);
            adj[i].insert(1);
        }
        if(x%2==0){
            q1.push(i);
        }
        else q2.push(i);
    }

    if(q2.size()<q1.size()){
        while(!q2.empty()){
            int u=q2.front();
            q2.pop();
            cout<<"? "<<u<<endl;

            for(int i=1;i<=n;i++){
                int x;
                cin>>x;
                if(x==1){
                    adj[u].insert(i);
                    adj[i].insert(u);
                }
            }
        }
    }
    else{
        while(!q1.empty()){
            int u=q1.front();
            q1.pop();
            cout<<"? "<<u<<endl;
            for(int i=1;i<=n;i++){
                int x;
                cin>>x;
                if(x==1){
                    adj[u].insert(i);
                    adj[i].insert(u);
                }
            }
        }
    }
    
    cout << "! " << endl;
    dfs(adj, 1, -1);

    return 0;
}
