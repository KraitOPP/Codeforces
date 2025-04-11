#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int getPos(const vector<int>& indices, int x) {
    return lower_bound(indices.begin(), indices.end(), x) - indices.begin();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    vector<int> indices;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals[i] = {l, r};
        indices.push_back(l);
        indices.push_back(r + 1); 
    }

    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

    vector<int> diff(indices.size() + 1, 0);

    for (auto& interval : intervals) {
        int start = getPos(indices, interval.first);
        int end = getPos(indices, interval.second + 1);
        diff[start] += 1;
        diff[end] -= 1;
    }

    int maxOverlap = 0, currentOverlap = 0;
    for (int i = 0; i < indices.size(); i++) {
        currentOverlap += diff[i];
        maxOverlap = max(maxOverlap, currentOverlap);
    }

    cout << maxOverlap << endl;
    return 0;
}
