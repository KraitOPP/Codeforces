#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
int t, n;
 
vector<pair<int, int>> arr;
 
long long ans;
 
ordered_set st;
 

void solve(vector<pair<int,int>> a, vector<int> &res, int n) {
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        res[a[i].second] += i;
    }
}

signed main() { 
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> co(n);
    vector<pair<int, int>> cod(n), top(n);

    for(int i = 0; i < n; i++) {
        cin >> co[i].first.first >> co[i].first.second;
        co[i].second = i;
        cod[i] = {co[i].first.first, i};
        top[i] = {co[i].first.second, i};
    }

    vector<int> res(n, 0);
    solve(cod, res, n);
    solve(top, res, n);

    sort(co.begin(), co.end());
    ordered_set st;

    for(int i = 0; i < n; i++) {
        int to_find = co[i].first.second;
        res[co[i].second] -= st.order_of_key(to_find); 
        st.insert(to_find);
    }

    for(int i = 0; i < n; i++) cout << res[i] << endl;

    return 0;
}
