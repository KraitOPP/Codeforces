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
    int n, q;
    cin >>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> pos(n, 0);
    while (q--){
        int l,r;
        cin>>l>>r;
        pos[l-1]++;
        if(r<n) pos[r]--;
    }

    for (int i=1; i<n; i++){
        pos[i]+=pos[i-1];
    }
    int res = 0;
    sort(a.begin(), a.end());
    sort(pos.begin(), pos.end());
    for (int i = 0; i < n; i++){
        res +=a[i]*pos[i];
    }
    cout << res << endl;

    return 0;
}