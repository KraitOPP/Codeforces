#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

bool dfs(vector<vector<int>> &adj, vector<int> &c, int node, vector<int> &res){
    bool flag;
    if(c[node]==1) flag=true;
    else flag=false;
    for(auto neigh: adj[node]){
        bool isRes = dfs(adj,c,neigh,res);
        if(isRes == true) flag=false;
    }

    if(flag) res.push_back(node);
    
    return c[node] == 0 ? true:false;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<int> c(n);
        vector<vector<int>> adj(n);
        int root;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            if(tmp==-1) root=i;
            else adj[tmp-1].push_back(i);
            cin>>c[i];
        }
        vector<int> res;
        dfs(adj,c,root,res);
        sort(res.begin(),res.end());
        if(res.size()==0) cout<<-1;
        else for(int i=0;i<res.size();i++) cout<<res[i]+1<<" ";
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}