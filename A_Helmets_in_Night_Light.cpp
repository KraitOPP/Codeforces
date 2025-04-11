#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,c;
        cin>>n>>c;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) cin>>a[i].first;
        for(int i=0;i<n;i++){
            cin>>a[i].second;
            a[i].second=min(a[i].second,c);
        }
        sort(a.begin(),a.end(),cmp);

        int cnt=0;
        int ans=c*cnt;
        for(int i=0;i<n;i++){
            if(cnt+a[i].first >= n){
                int tmp = n-cnt;
                ans+=a[i].second*tmp;
                break;
            }
            ans+=a[i].first*a[i].second;
            cnt+=a[i].first;
        }
        cout<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}