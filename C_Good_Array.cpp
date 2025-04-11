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
        vector<int> a(n);
        map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
            sum+=a[i];
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            int rq = sum-a[i];
            if((rq%2)==0){
                rq=rq/2;
                if((rq!=a[i] && mp[rq]>0) || (rq==a[i] && mp[a[i]]>1)) res.push_back(i+1);
            }
        }
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        cout<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}