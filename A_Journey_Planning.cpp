#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        map<int,int> pr;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            pr[i-a[i]]+=a[i];
        }
        int res=0;
        for(auto itr : pr){
            res=max(res,itr.second);
        }
        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}