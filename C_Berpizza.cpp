#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define int long long

struct CustomComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

signed main() {
    fastio();
    int q;
    cin >> q;

    // Use custom comparator in the priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomComparator> pq;
    queue<int> orderQueue;
    set<int> removed;
    int cnt = 1;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            pq.push({x, cnt});
            orderQueue.push(cnt);
            cnt++;
        } else if (type == 2) {
            while (removed.find(orderQueue.front()) != removed.end()) orderQueue.pop();
            cout << orderQueue.front() << " ";
            removed.insert(orderQueue.front());
        } else {
            while (removed.find(pq.top().second) != removed.end()) pq.pop();
            cout << pq.top().second << " ";
            removed.insert(pq.top().second);
        }
    }
    cout << endl;
    return 0;
}
