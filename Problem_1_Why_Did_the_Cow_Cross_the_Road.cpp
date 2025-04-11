#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    // freopen("helpcross.in", "r", stdin);
    cin>>n>>m;
    vector<int> a(n);
    vector<pair<int,int>> b(m);
    multiset<int> st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    for(int i=0;i<n;i++){
        cin>>b[i].first>>b[i].second;
    }
    sort(b.begin(),b.end());

    int res=0;
    for(int i=0;i<m;i++){
        if(st.empty()) break;
        auto itr = st.lower_bound(b[i].first);
        if(itr!=st.end() && *itr<=b[i].second){
            res++;
            st.erase(itr);
        }
    }
    // freopen("helpcross.out","w",stdout);
    cout<<res<<endl;


    return 0;
}