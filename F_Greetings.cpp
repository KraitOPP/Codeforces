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
        vector<pair<int,int>> a(n);
        vector<int> s;
        for(int i=0;i<n;i++){
             cin>>a[i].first>>a[i].second;
             s.push_back(a[i].second);
        }

        sort(a.begin(),a.end());    
        sort(s.begin(),s.end());
        int res=0;
        for(int i=0;i<n;i++){
            int r = a[i].second;
            int pos = lower_bound(s.begin(),s.end(),r) - s.begin();
            res+=pos;
            s.erase(s.begin() + pos);
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}