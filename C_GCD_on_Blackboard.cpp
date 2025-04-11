#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
const int inf = 1e18, mod = 1e9+7;

class SegmentTree {
    vector<int> arr;

public:
    SegmentTree(int sz) {
        arr.resize(4 * sz + 5);
    }

    void build(const vector<int> &a, int idx, int l, int r) {
        if (l == r) {
            arr[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * idx + 1, l, mid);
        build(a, 2 * idx + 2, mid + 1, r);
        arr[idx] = __gcd(arr[2 * idx + 1], arr[2 * idx + 2]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;  
        }
        if (l <= start && end <= r) {
            return arr[node];
        }
        int mid = (start + end) / 2;
        int p1 = query(2 * node + 1, start, mid, l, r);
        int p2 = query(2 * node + 2, mid + 1, end, l, r);
        return __gcd(p1, p2);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree tree(n);
    tree.build(a, 0, 0, n - 1);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int leftGCD = (i > 0) ? tree.query(0, 0, n - 1, 0, i - 1) : 0;
        int rightGCD = (i < n - 1) ? tree.query(0, 0, n - 1, i + 1, n - 1) : 0;
        res = max(res, __gcd(leftGCD, rightGCD));
    }

    cout << res << endl;

    return 0;
}
