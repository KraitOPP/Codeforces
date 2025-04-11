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

    set<int> st;
    vector<set<int>> adj(n + 1);    

    while (!st.empty()) {
        int x = *st.begin();
        st.erase(x);

        cout << "? " << x << endl;
        
    }
    
    cout << "! " << endl;
    dfs(adj, 1, -1);

    return 0;
}
