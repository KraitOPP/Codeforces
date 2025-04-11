#include <bits/stdc++.h>
using namespace std;
#define int long long
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
        vector<int> a;
        int prv=-1;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            if(tmp!=prv) a.push_back(tmp);
            prv=tmp;
        }
        int cnt=2;
        for(int i=1;i<a.size()-1;i++){
            if(a[i]>=a[i-1] && a[i+1]>=a[i]) continue;
            else if(a[i]<=a[i-1] && a[i+1]<=a[i]) continue;
            cnt++;
        }
        bool flag=1;
        for(int i=0;i<a.size();i++){
            if(a[i]!=a[0]) flag=0;
        }
        if(flag) cout<<1<<endl;
        else cout<<cnt<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}