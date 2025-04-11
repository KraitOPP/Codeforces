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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> res;
        res.push_back(a[0]);
        for(int i=1;i<n-1;i++){
            if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])) res.push_back(a[i]);
        }
        res.push_back(a[n-1]);
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        cout<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}