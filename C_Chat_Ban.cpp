#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        auto begin = chrono::high_resolution_clock::now();

        int k, x;
        cin >> k >> x;

        int l = k * (k + 1) / 2;
        if (x <= l)
        {
            int low = 1, high = k, ans = k;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int sum = mid * (mid + 1) / 2;
                if (sum >= x)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            cout << ans << endl;
        }
        else
        {
            int low = 1, high = k - 1, ans = k-1;
            x -= l;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int sum = mid * (2 * k - mid - 1) / 2;
                if (sum >= x)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            
            cout << ans + k << endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }

    return 0;
}
