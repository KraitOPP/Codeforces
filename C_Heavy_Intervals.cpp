#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<int> a(n),b(n),c(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) cin>>c[i];
        int res=0;
        sort(b.begin(),b.end());
        sort(c.begin(),c.end(),greater<int>());
        set<int> st(a.begin(),a.end());

        for(int i=0;i<n;i++){
            auto itr = --(st.lower_bound(b[i]));
            int x = *itr;
            st.erase(x);
            a[i]=(b[i]-x);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++) res+=c[i]*(a[i]);
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}