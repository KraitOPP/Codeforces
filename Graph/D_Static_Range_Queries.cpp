#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18, mod = 1e9 + 7;
int n, q;
vector<int> a, pre, lazy;

void buildSegmentTree(int node, int start, int end) {
    if (start == end) {
        pre[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    buildSegmentTree(2 * node, start, mid);
    buildSegmentTree(2 * node + 1, mid + 1, end);
    pre[node] = pre[2 * node] + pre[2 * node + 1];
}

void updateRange(int node, int start, int end, int l, int r, int val) {
    if (lazy[node] != 0) {
        pre[node] += (end - start + 1) * lazy[node];
        if (start != end) { 
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l) return;

    if (start >= l && end <= r) {
        pre[node] += (end - start + 1) * val;
        if (start != end) { 
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);
    pre[node] = pre[2 * node] + pre[2 * node + 1];
}

int queryRange(int node, int start, int end, int l, int r) {
    if (lazy[node] != 0) {
        pre[node] += (end - start + 1) * lazy[node];
        if (start != end) { 
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l) return 0;

    if (start >= l && end <= r) return pre[node];

    int mid = (start + end) / 2;
    return queryRange(2 * node, start, mid, l, r) + queryRange(2 * node + 1, mid + 1, end, l, r);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    a = vector<int>(n,0);
    pre = vector<int>(4 * n + 10, 0);
    lazy = vector<int>(4 * n + 10, 0);

    buildSegmentTree(1, 0, n - 1);
    
    for(int i=0;i<n;i++){
        int l, r, up;
        cin >> l >> r >> up;
        updateRange(1, 0, n - 1, l - 1, r - 1, up);
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        cout << queryRange(1, 0, n - 1, l - 1, r - 1) << endl;
    }

    return 0;
}
