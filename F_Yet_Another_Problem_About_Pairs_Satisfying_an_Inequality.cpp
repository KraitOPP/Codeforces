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
        vector<pair<int,int>> a;
        for(int i=1;i<=n;i++){
            int tmp;
            cin>>tmp;
            if(tmp<i){
                a.push_back({tmp,i});
            }
        }
        sort(a.begin(),a.end());
        int res=0;
        for(int i=0;i<a.size();i++){
            auto it = lower_bound(a.begin(), a.end(), make_pair(a[i].second+1, 0LL)) - a.begin();
            res += a.size() - it;
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}