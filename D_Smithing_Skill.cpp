#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    long long max_experience = 0;

    for (int j = 0; j < m; j++) {
        int remaining_ingots = c[j];
        while (true) {
            bool crafted = false;
            for (int i = 0; i < n; i++) {
                int net_cost = a[i] - b[i];
                if (remaining_ingots >= a[i]) {
                    int cycles = remaining_ingots / a[i];
                    remaining_ingots -= cycles * net_cost;
                    max_experience += 2 * cycles;
                    crafted = true;
                }
            }
            if (!crafted) break;
        }
    }

    cout << max_experience << endl;

    return 0;
}
