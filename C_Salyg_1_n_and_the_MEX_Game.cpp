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
        unordered_set<int> a;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            a.insert(tmp);
        }
        int mex=0;
        while(a.count(mex)) mex++;
        cout<<mex<<endl;
        cout.flush();
        int x;
        cin>>x;
        while(x!=-1){
            cout<<x<<endl;
            cout.flush();
            cin>>x;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}