#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cstdlib>
using namespace std;
 
struct State {
    int cost, u, v;
    bool operator>(const State &other) const {
        return cost > other.cost;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, s1, s2;
        cin >> n >> s1 >> s2;
 
        int m1;
        cin >> m1;
        vector<vector<int>> graph1(n+1);
        for (int i = 0; i < m1; i++){
            int u, v;
            cin >> u >> v;
            graph1[u].push_back(v);
            graph1[v].push_back(u);
        }
 
        int m2;
        cin >> m2;
        vector<vector<int>> graph2(n+1);
        for (int i = 0; i < m2; i++){
            int u, v;
            cin >> u >> v;
            graph2[u].push_back(v);
            graph2[v].push_back(u);
        }
 
        vector<unordered_set<int>> neigh1(n+1), neigh2(n+1);
        for (int i = 1; i <= n; i++){
            for (int nb : graph1[i])
                neigh1[i].insert(nb);
        }
        for (int i = 1; i <= n; i++){
            for (int nb : graph2[i])
                neigh2[i].insert(nb);
        }
 
        vector<bool> terminal(n+1, false);
        for (int w = 1; w <= n; w++){
            for (int nb : neigh1[w]){
                if (neigh2[w].find(nb) != neigh2[w].end()){
                    terminal[w] = true;
                    break;
                }
            }
        }
 
        const int INF = 1e9;
        vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
        dist[s1][s2] = 0;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, s1, s2});
 
        int ans = -1;
        while(!pq.empty()){
            State cur = pq.top();
            pq.pop();
            int d = cur.cost, u = cur.u, v = cur.v;
            if(d != dist[u][v])
                continue;
 
            if(u == v && terminal[u]){
                ans = d;
                break;
            }
 

            for (int u2 : graph1[u]){
                for (int v2 : graph2[v]){
                    int nd = d + abs(u2 - v2);
                    if(nd < dist[u2][v2]){
                        dist[u2][v2] = nd;
                        pq.push({nd, u2, v2});
                    }
                }
            }
        }
 
        cout << ans << "\n";
    }
    return 0;
}
