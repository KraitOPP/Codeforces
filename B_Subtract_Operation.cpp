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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        bool flag=false;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        for(int i=0;i<n;i++){
            int num=a[i]+k;
            mp[a[i]]--;
            if(mp[num]>0){
                flag=true;
                break;
            }
            mp[a[i]]++;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}