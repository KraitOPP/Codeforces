#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prime;
    const int maxN = 100000 + 5;

    void SieveOfEratosthenes(){
        prime.assign(maxN, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p < maxN; p++) {
            if (prime[p]) {
                for (int i = p * p; i < maxN; i += p)
                    prime[i] = false;
            }
        }
    }

    void buildSegTree(vector<int> &a, vector<int> &segTree, int node, int start, int end){
        if (start == end) {
            segTree[node] = a[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildSegTree(a, segTree, 2 * node, start, mid);
        buildSegTree(a, segTree, 2 * node + 1, mid + 1, end);
        segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    }

    void rangeUpdate(vector<int> &segTree, vector<int> &lazy, int node, int start, int end, int l, int r, int val){
        if (lazy[node] != 0) {
            segTree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            segTree[node] += val;
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        int mid = start + (end - start) / 2;
        rangeUpdate(segTree, lazy, 2 * node, start, mid, l, r, val);
        rangeUpdate(segTree, lazy, 2 * node + 1, mid + 1, end, l, r, val);
        segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    }

    int queryWithLazy(vector<int> &segTree, vector<int> &lazy, int node, int start, int end, int s, int e){
        if (start > e || end < s) return 0;
        if (lazy[node] != 0) {
            segTree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start >= s && end <= e) return segTree[node];
        int mid = start + (end - start) / 2;
        int left = queryWithLazy(segTree, lazy, 2 * node, start, mid, s, e);
        int right = queryWithLazy(segTree, lazy, 2 * node + 1, mid + 1, end, s, e);
        return max(left, right);
    }

    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SieveOfEratosthenes();
        unordered_map<int, set<int>> mp;
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            if (prime[v]) {
                mp[v].insert(i);
            }
        }
        vector<int> pre(n, 0), suff(n, 0);
        for (auto &pr : mp) {
            int f = *pr.second.begin();
            int l = *pr.second.rbegin();
            pre[f] = 1;
            suff[l] = 1;
        }
        for (int i = 1; i < n; i++) pre[i] += pre[i - 1];
        for (int i = n - 2; i >= 0; i--) suff[i] += suff[i + 1];
        int m = n - 1;
        vector<int> arr(max(0, m), 0);
        if (m > 0) {
            for (int i = 0; i < m; i++) {
                arr[i] = pre[i] + suff[i + 1];
            }
        }
        vector<int> segTree(4 * max(1, m), 0), lazy(4 * max(1, m), 0);
        if (m > 0) buildSegTree(arr, segTree, 1, 0, m - 1);
        vector<int> res;
        res.reserve(queries.size());
        for (auto &q : queries) {
            int idx = q[0], val = q[1];
            int prvval = nums[idx];
            if ( prime[prvval]) {
                auto &s = mp[prvval];
                int focc = *s.begin();
                int locc = *s.rbegin();
                s.erase(idx);
                if (s.empty()) {
                    if (focc < m) rangeUpdate(segTree, lazy, 1, 0, m - 1, focc, m - 1, -1);
                    if (locc - 1 >= 0) rangeUpdate(segTree, lazy, 1, 0, m - 1, 0, locc - 1, -1);
                } else {
                    int fnew = *s.begin();
                    int lnew = *s.rbegin();
                    if (idx == focc) {
                        if (focc < m) rangeUpdate(segTree, lazy, 1, 0, m - 1, focc, m - 1, -1);
                        if (fnew < m) rangeUpdate(segTree, lazy, 1, 0, m - 1, fnew, m - 1, +1);
                    }
                    if (idx == locc) {
                        if (locc - 1 >= 0) rangeUpdate(segTree, lazy, 1, 0, m - 1, 0, locc - 1, -1);
                        if (lnew - 1 >= 0) rangeUpdate(segTree, lazy, 1, 0, m - 1, 0, lnew - 1, +1);
                    }
                }
            }
            if ( prime[val]) {
                auto &s = mp[val];
                if (s.empty()) {
                    if (idx < m) rangeUpdate(segTree, lazy, 1, 0, m - 1, idx, m - 1, +1);
                    if (idx - 1 >= 0) rangeUpdate(segTree, lazy, 1, 0, m - 1, 0, idx - 1, +1);
                    s.insert(idx);
                } else {
                    int focc = *s.begin();
                    int locc = *s.rbegin();
                    s.insert(idx);
                    int fnew = min(focc, idx);
                    int lnew = max(locc, idx);
                    if (idx < focc) {
                        if (focc < m) rangeUpdate(segTree, lazy, 1, 0, m - 1, focc, m - 1, -1);
                        if (idx < m) rangeUpdate(segTree, lazy, 1, 0, m - 1, idx, m - 1, +1);
                    }
                    if (idx > locc) {
                        if (locc - 1 >= 0) rangeUpdate(segTree, lazy, 1, 0, m - 1, 0, locc - 1, -1);
                        if (idx - 1 >= 0) rangeUpdate(segTree, lazy, 1, 0, m - 1, 0, idx - 1, +1);
                    }
                }
            }
            nums[idx] = val;
            int best = (m > 0 ? queryWithLazy(segTree, lazy, 1, 0, m - 1, 0, m - 1) : 0);
            res.push_back(best);
        }
        return res;
    }
};
