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
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<int> a(n),b(n), pre(n);
        inp(a,n);
        inp(b,n);
        for(int i=0;i<n;i++){
            if(i==0) pre[i]=b[i];
            else pre[i]=pre[i-1]+b[i];
        }

        vector<int> cnt(n+1,0), left(n+1,0);
        for(int i=0;i<n;i++){
            int prv = i>0 ? pre[i-1] : 0;
            int idx = lower_bound(pre.begin(),pre.end(),prv+a[i])-pre.begin();
            if(idx<n && pre[idx]==prv+a[i]){
                cnt[i]++;
                cnt[idx+1]--;
                // cout<<" 1 ";
            } 
            else if(idx==i){
                left[i]+=a[i];
            }
            else{
                idx-=1;
                // cout<<idx+1<<" "<<prv<<" "<<a[i]<<" "<<pre[idx]<<endl;
                cnt[i]++;
                cnt[idx+1]--;
                left[idx+1] += prv+a[i]-pre[idx];
                // cout<<left[idx+1]<<endl;
                // cout<<left[idx+1]<<" "<<a[i]<<endl;
            }
        }

        for(int i=0;i<n;i++){
            // cout<<left[i]<<" ";
            cnt[i]+= i>0 ? cnt[i-1] : 0;
            // cout<<cnt[i]<<" "<<left[i]<<endl;
        }

        for(int i=0;i<n;i++){
            cout<<cnt[i]*b[i]+left[i]<<" ";
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}