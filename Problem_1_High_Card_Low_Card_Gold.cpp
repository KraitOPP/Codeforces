#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    freopen("cardgame.in", "r", stdin);
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    set<int> distinctElements(a.begin(), a.end());
    vector<int> b;

    for(int i = 1; i <= 2 * n; i++) {
        if(distinctElements.find(i) == distinctElements.end()) {
            b.push_back(i);
        }
    }

    int result = 0;
    
    sort(a.begin(), a.begin() + n/2, greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int j = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        if (a[i] < b[j]) {
            result++;
        j++;
        }
    }
    
    sort(a.begin() + n / 2, a.end());
    
    j = b.size() - 1;
    for (int i = n / 2; i < n; i++) {
        if (a[i] > b[j]) {
            result++;
        j--;
        }
    }
    freopen("cardgame.out", "w", stdout);
    cout << result << endl;
    return 0;
}
