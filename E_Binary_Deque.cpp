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
        int n,s;
        cin>>n>>s;
        vector<int> a(n);
        vector<int> pre(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            pre[i]=sum;
        }
        int ans=INT_MAX;
        for(int i = 0; i < n; ++i) {
            int l = i, r = n - 1, pos = -1;
            while(l <= r) {
                int mid = l+(r-l)/2;
                int x = pre[mid] - (i>0 ? pre[i-1]:0);
                if(x <= s) {
                    pos = mid;
                    l = mid + 1;
                } 
                else r = mid - 1;
            }
            int x=-1;
            if(pos!=-1) x=pre[pos] - (i>0 ? pre[i-1]:0);
            if(pos == -1 || x != s) continue;
            ans = min(ans, n - (pos - i + 1));
        }
        if(ans==INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}