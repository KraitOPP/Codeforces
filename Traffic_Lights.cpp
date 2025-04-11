#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,n;
    cin>>x>>n;
    vi a(n);
    inp(a,n);
    set<int> pos({0, x});
    multiset<int> res({x});
    for(int i=0;i<n;i++){
        auto itr1 = pos.upper_bound(a[i]);
        auto itr2 = itr1;
        itr2--;
        res.erase(res.find(*itr1-*itr2));
        res.insert(a[i]-*itr2);
        res.insert(*itr1-a[i]);
        pos.insert(a[i]);

        cout<<*(res.rbegin())<<" ";
    }
    cout<<endl;
    return 0;
}