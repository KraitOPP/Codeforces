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
        int n, q;
        cin >> n >> q;
        vector<string> a;
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> BG(n, -1);
        vector<int> BR(n, -1);
        vector<int> BY(n, -1);
        vector<int> GR(n, -1);
        vector<int> GY(n, -1);
        vector<int> RY(n, -1);
        vector<int> BG2(n, -1);
        vector<int> BR2(n, -1);
        vector<int> BY2(n, -1);
        vector<int> GR2(n, -1);
        vector<int> GY2(n, -1);
        vector<int> RY2(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == "BG")
            {
                BG[i] = i;
            }
            else if (i != 0)
                BG[i] = BG[i - 1];
            if (a[i] == "BR")
            {
                BR[i] = i;
            }
            else if (i != 0)
                BR[i] = BR[i - 1];
            if (a[i] == "BY")
            {
                BY[i] = i;
            }
            else if (i != 0)
                BY[i] = BY[i - 1];
            if (a[i] == "GR")
            {
                GR[i] = i;
            }
            else if (i != 0)
                GR[i] = GR[i - 1];
            if (a[i] == "GY")
            {
                GY[i] = i;
            }
            else if (i != 0)
                GY[i] = GY[i - 1];
            if (a[i] == "RY")
            {
                RY[i] = i;
            }
            else if (i != 0)
                RY[i] = RY[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == "BG")
            {
                BG2[i] = i;
            }
            else if (i != n - 1)
                BG2[i] = BG2[i + 1];
            if (a[i] == "BR")
            {
                BR2[i] = i;
            }
            else if (i != n - 1)
                BR2[i] = BR2[i + 1];
            if (a[i] == "BY")
            {
                BY2[i] = i;
            }
            else if (i != n - 1)
                BY2[i] = BY2[i + 1];
            if (a[i] == "GR")
            {
                GR2[i] = i;
            }
            else if (i != n - 1)
                GR2[i] = GR2[i + 1];
            if (a[i] == "GY")
            {
                GY2[i] = i;
            }
            else if (i != n - 1)
                GY2[i] = GY2[i + 1];
            if (a[i] == "RY")
            {
                RY2[i] = i;
            }
            else if (i != n - 1)
                RY2[i] = RY2[i + 1];
        }

        while (q--)
        {
            int src, dest;
            cin >> src >> dest;
            string s1 = a[src - 1];
            string s2 = a[dest - 1];
            if (s2 > s1)
            {
                if (s1 == "BG" && s2 == "RY")
                {
                    int ans = INT_MAX;
                    if (BR[src - 1] != -1)
                        ans = min(ans, abs(BR[src - 1] - src + 1) + dest - 1 - BR[src - 1]);
                    if (BY[src - 1] != -1)
                        ans = min(ans, abs(BY[src - 1] - src + 1) + dest - 1 - BY[src - 1]);
                    if (GR[src - 1] != -1)
                        ans = min(ans, abs(GR[src - 1] - src + 1) + dest - 1 - GR[src - 1]);
                    if (GY[src - 1] != -1)
                        ans = min(ans, abs(GY[src - 1] - src + 1) + dest - 1 - GY[src - 1]);
                    if (ans == INT_MAX)
                        cout << -1 << endl;
                    else
                        cout << ans << endl;
                }
                else if (s1 == "BR" && s2 == "GY")
                {
                    int ans = INT_MAX;
                    if (BG[src - 1] != -1)
                        ans = min(ans, abs(BG[src - 1] - src + 1) + dest - 1 - BG[src - 1]);
                    if (BY[src - 1] != -1)
                        ans = min(ans, abs(BY[src - 1] - src + 1) + dest - 1 - BY[src - 1]);
                    if (GR[src - 1] != -1)
                        ans = min(ans, abs(GR[src - 1] - src + 1) + dest - 1 - GR[src - 1]);
                    if (RY[src - 1] != -1)
                        ans = min(ans, abs(RY[src - 1] - src + 1) + dest - 1 - RY[src - 1]);
                    if (ans == INT_MAX)
                        cout << -1 << endl;
                    else
                        cout << ans << endl;
                }
                else if (s1 == "BY" && s2 == "GR")
                {
                    int ans = INT_MAX;
                    if (BG[src - 1] != -1)
                        ans = min(ans, abs(BG[src - 1] - src + 1) + dest - 1 - BG[src - 1]);
                    if (BR[src - 1] != -1)
                        ans = min(ans, abs(BR[src - 1] - src + 1) + dest - 1 - BR[src - 1]);
                    if (GY[src - 1] != -1)
                        ans = min(ans, abs(GY[src - 1] - src + 1) + dest - 1 - GY[src - 1]);
                    if (RY[src - 1] != -1)
                        ans = min(ans, abs(RY[src - 1] - src + 1) + dest - 1 - RY[src - 1]);
                    if (ans == INT_MAX)
                        cout << -1 << endl;
                    else
                        cout << ans << endl;
                }
                else
                    cout << abs(dest - src) << endl;
            }
            else
            {
                if (s1 == "RY" && s2 == "BG")
                {
                    int ans = INT_MAX;
                    if (BR2[dest - 1] != -1)
                        ans = min(ans, abs(BR2[dest - 1] - dest + 1) + BR2[dest - 1] - src + 1);
                    if (BY2[dest - 1] != -1)
                        ans = min(ans, abs(BY2[dest - 1] - dest + 1) + BY2[dest - 1] - src + 1);
                    if (GR2[dest - 1] != -1)
                        ans = min(ans, abs(GR2[dest - 1] - dest + 1) + GR2[dest - 1] - src + 1);
                    if (GY2[dest - 1] != -1)
                        ans = min(ans, abs(GY2[dest - 1] - dest + 1) + GY2[dest - 1] - src + 1);
                    if (ans == INT_MAX)
                        cout << -1 << endl;
                    else
                        cout << ans << endl;
                }
                else if (s1 == "GY" && s2 == "BR")
                {
                    int ans = INT_MAX;
                    if (BG2[dest - 1] != -1)
                        ans = min(ans, abs(BG2[dest - 1] - dest + 1) + BG2[dest - 1] - src + 1);
                    if (BY2[dest - 1] != -1)
                        ans = min(ans, abs(BY2[dest - 1] - dest + 1) + BY2[dest - 1] - src + 1);
                    if (GR2[dest - 1] != -1)
                        ans = min(ans, abs(GR2[dest - 1] - dest + 1) + GR2[dest - 1] - src + 1);
                    if (RY2[dest - 1] != -1)
                        ans = min(ans, abs(RY2[dest - 1] - dest + 1) + RY2[dest - 1] - src + 1);
                    if (ans == INT_MAX)
                        cout << -1 << endl;
                    else
                        cout << ans << endl;
                }
                else if (s1 == "GR" && s2 == "BY")
                {
                    int ans = INT_MAX;
                    if (BG2[dest - 1] != -1)
                        ans = min(ans, abs(BG2[dest - 1] - dest + 1) + BG2[dest - 1] - src + 1);
                    if (BR2[dest - 1] != -1)
                        ans = min(ans, abs(BR2[dest - 1] - dest + 1) + BR2[dest - 1] - src + 1);
                    if (GY2[dest - 1] != -1)
                        ans = min(ans, abs(GY2[dest - 1] - dest + 1) + GY2[dest - 1] - src + 1);
                    if (RY2[dest - 1] != -1)
                        ans = min(ans, abs(RY2[dest - 1] - dest + 1) + RY2[dest - 1] - src + 1);
                    if (ans == INT_MAX)
                        cout << -1 << endl;
                    else
                        cout << ans << endl;
                }
                else
                    cout << abs(src - dest) << endl;
            }
        }
    }
    return 0;
}