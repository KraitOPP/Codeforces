#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)


signed main(){ 
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char x;
                cin>>x;
                if(x=='1'){
                    adj[i].push_back(j);
                    deg[j]++;
                }
            }
        }

        vector<set<int>> res(n);
        int cnt=1;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0) q.push({i,-1});
        }
        while(!q.empty()){
            int u=q.front().first;
            int par = q.front().second;
            q.pop();
            if(res[u].size()==0){
                res[u].insert(cnt++);
                for(auto v:adj[u]){
                    q.push({v,u});
                }
            }
            if(par!=-1){
                for(auto num: res[par]){
                    res[u].insert(num);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(res[i].size()==0) res[i].insert(cnt++);
        }
        for(int i=0;i<n;i++){
            cout<<res[i].size()<<" ";
            for(auto x:res[i]) cout<<x<<" ";
            cout<<endl;
        }
    }
    return 0;
}