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
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            a[tmp-1]++;
        }
        sort(a.begin(),a.end(),greater<int>());
        int res=0;
        int cnt=a[0];
        for(int i=0;i<n;i++){
            if(cnt>0){
                res+=min(cnt,a[i]);
                cnt=min(cnt-1,a[i]-1);
            }
        }
        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}