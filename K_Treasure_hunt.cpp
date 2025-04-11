#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int MOD = 1000000007;

int decreasing(vector<pair<int , pair<int , int>>>& arr, int num) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].first > num) { 
            result = mid;  
            low = mid + 1; 
        } else {
            high = mid - 1;    
        }
    }

    return result;
}

void precompute(vector<pair<int , pair<int , int>>> &chest , vector<vector<int>> &coins) {
    int n = coins.size();
    int m = coins[0].size();

    for(int i = 1; i < n; i++)
    {
        if(chest[i - 1].second.first == 0)
            coins[i][0] = chest[i - 1].second.second;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            coins[i][j] = coins[i - 1][j];
            if(j - chest[i - 1].second.first >= 0)
                coins[i][j] = max(coins[i][j] , coins[i - 1][j - chest[i - 1].second.first] + chest[i - 1].second.second);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    
    int n , q;
    cin >> n >> q;
    vector<pair<int , pair<int , int>>> chest;
    for(int i = 0; i < n; i++)
    {
        int c , m , t;
        cin >> c >> m >> t;
        chest.push_back({t , {m , c}});
    }

    sort(chest.rbegin() , chest.rend());

    vector<vector<int>> coins(n + 1 , vector<int>(1e4 + 10 , 0));

    precompute(chest , coins);

    for(int i = 0; i < q; i++)
    {
        int t , B;
        cin >> t >> B;
        if(n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int idx = decreasing(chest , t);
        cout << coins[idx + 1][B] << endl;
    }
    return 0;
}