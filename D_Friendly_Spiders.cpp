#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define endl "\n"
#define pii pair<int, int>
#define vi vector<int>

typedef long long ll;

#define MAXN 300000
vector<vector<int>> sieve(MAXN + 1);

void calc_sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (sieve[i].empty()) {
            for (int j = i; j <= MAXN; j += i) {
                sieve[j].push_back(i);
            }
        }
    }
}

signed main() {
    fastio();
    calc_sieve();
    
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int s, t;
    cin >> s >> t;
    s--, t--;
    
    if (s == t) {
        cout << 1 << endl;
        cout << s + 1 << endl;
        return 0;
    }

    if (__gcd(a[s], a[t]) > 1) {
        cout << 2 << '\n' << s + 1 << ' ' << t + 1;
        return 0;
    }

    if (a[s] == 1 || a[t] == 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> adj(MAXN+1);
    
    for (int i = 0; i < n; i++) {
        for (auto v : sieve[a[i]]) {
            adj[v].push_back(i);
        }
    }

    vector<int>  parent(MAXN,-1), vis(n+1,0), primevis(MAXN+1,0);     
    queue<int> q;
    
    q.push(s);
    parent[s] = -1;
    vis[s]=1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if(top==t){
            vi res;
            while(top!=-1){
                res.push_back(top+1);
                top=parent[top];
            }
            reverse(res.begin(), res.end());
            cout<<res.size()<<endl;
            for(auto num: res) cout<<num<<" ";
            cout<<endl;

            return 0;
        }
        for(auto pr: sieve[a[top]]){
            if(primevis[pr]) continue;
            for(auto neigh: adj[pr]){
                if(vis[neigh]==0){
                    q.push(neigh);
                    parent[neigh]=top;
                    vis[neigh]=1;
                }
            }
            primevis[pr]=1;
        }
    }
    
    cout << -1 << endl;
    return 0;
}
