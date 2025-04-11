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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end(),greater<int>());
        priority_queue<int> q;
        int res=0;
        if(n%2==1) res+=a[n-1];
        for(int i=1;i<n;i+=2){
            res+=a[i-1]-a[i];
            q.push(a[i-1]-a[i]);
        }
        while(!q.empty() && k>0){
            int top = q.top();
            q.pop();
            res-=min(top,k);
            k-=min(top,k);
        }
        cout<<max(0ll,res)<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}