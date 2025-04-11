#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(vector<int> &degree, int n, vector<vector<int>> &adj, vector<int> &result, vector<int> a){
    queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i] == 1) q.push(i);
        }
        
        while(!q.empty()){
            int top = q.front();
            if(q.size()>=2){
                int u = q.front();
                q.pop();
                int v = q.front();
                q.pop();
                if(a[u] > a[v]){
                    q.push(v);
                    top=u;
                }
                else{
                    q.push(u);
                    top=v;
                }
            }
            else{
                q.pop();
            }
            result.push_back(top+1);
            for(int i=0;i<adj[top].size();i++){
                degree[adj[top][i]]--;
                if(degree[adj[top][i]] == 1){
                    q.push(adj[top][i]);
                }
            }
            
        }
}

signed main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<int> a(n);
	    for(int i= 0 ;i<n;i++) cin>>a[i];
	    vector<vector<int>> adj(n);
	    vector<int> degree(n,0);
	    
	    for(int i=0;i<n-1;i++){
	        int u,v;
	        cin>>u>>v;
	        adj[u-1].push_back(v-1);
	        adj[v-1].push_back(u-1);
	        degree[u-1]++;
	        degree[v-1]++;
	    }
	    vector<int> result;
        solve(degree,n,adj,result,a);
        cout<<result.size()<<endl;
        for(int i = 0;i<result.size();i++) cout<<result[i]<<" ";
        cout<<endl;
	}

}