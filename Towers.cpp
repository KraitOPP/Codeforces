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
    int n;
    cin>>n;
    int res=0;
    multiset<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        auto itr = st.upper_bound(x);
        if(itr==st.end()){
            res++;
        }
        else{
            st.erase(itr);
        }
        st.insert(x);
    }

    cout<<res<<endl;

    return 0;
}