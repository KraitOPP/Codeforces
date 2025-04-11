#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)
vector<int> tree;

void build(vector<int> &diff, int node, int start, int end) {
    if (start == end) {
        tree[node] = diff[start];
    } else {
        int mid = (start + end) / 2;
        build(diff, 2 * node, start, mid);
        build(diff, 2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(vector<int> &diff, int node, int start, int end, int idx, int val) {
    if (start == end) {
        diff[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(diff, 2 * node, start, mid, idx, val);
        } else {
            update(diff, 2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return LLONG_MIN;  
    }
    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return max(p1, p2);
}

bool helper(int i, int mid, int p, int n) {
    int x = query(1, 0, n - 2, i, mid);
    return x <= p;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    if (n == 1) {
        int a;
        cin >> a;  
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int type, idx, p;
            cin >> type >> idx >> p; 
            if(type == 2)
                cout << 1 << endl;
        }
        return 0;
    }

    tree.resize(4 * (n - 1) + 1);  
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++) diff[i] = abs(a[i + 1] - a[i]);

    build(diff, 1, 0, n - 2);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type, idx, p;
        cin >> type;

        if (type == 1) {
            cin >> idx >> p;
            idx--;  

            if (idx == 0) {
                a[0] = p;
                update(diff, 1, 0, n - 2, 0, abs(a[1] - a[0]));
            } else if (idx == n - 1) {
                a[n - 1] = p;
                update(diff, 1, 0, n - 2, n - 2, abs(a[n - 1] - a[n - 2]));
            } else {
                a[idx] = p;
                update(diff, 1, 0, n - 2, idx - 1, abs(a[idx] - a[idx - 1]));
                update(diff, 1, 0, n - 2, idx, abs(a[idx + 1] - a[idx]));
            }
        } else {
            cin >> idx >> p;
            idx--;  

            int l = idx;
            int r = n - 2; 
            int ans = idx;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (helper(idx, mid, p, n)) {
                    ans = mid + 1;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            cout << ans + 1 << endl;
        }
    }

    return 0;
}
