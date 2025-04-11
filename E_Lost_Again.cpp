#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
const int mod = 1e9+7;
vector<int> cnt,ans;
int n;

void dfs(vector<vector<int>> &adj, int node, int p){
    cnt[node]=1;
    for(auto child: adj[node]){
        if(child!=p){
            dfs(adj,child,node);
            cnt[node]+=cnt[child];
            ans[node]+=ans[child]+cnt[child];
        }
    }
}

void dfs2(vector<vector<int>> &adj, int node, int p){
    for(auto child: adj[node]){
        if(child!=p){
            ans[child]=ans[node]-cnt[child]+n-cnt[child];
            dfs2(adj,child,node);
        }
    }
}

int binExp(int a, int b, int M){
    a %= M;
    int ans = 1;
    while(b){
        if(b & 1)
            ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    cnt.resize(n);
    ans.resize(n);
    for(int i=0;i<n;i++) cnt[i]=0,ans[i]=0;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs(adj,0,-1);
    dfs2(adj,0,-1);
    
    int sum=0;
    for(int i=0;i<n;i++) sum+=ans[i];
    sum/=2;
    int x = (n*(n+1))/2;
    if(x==0){
        cout << 0 << endl;
        return 0;
    }
    cout << sum << " " << x << endl;
    int gc = __gcd(x,sum);
    x/=gc;
    sum/=gc;
    cout<<((sum%mod)*(binExp(x,mod-2,mod)%mod))%mod<<endl;

    return 0;
}