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
        int n,m;
        cin>>n>>m;
        string s,r;
        cin>>s;
        vector<int> a(m);
        map<int,int> mp;
        for(int i=0;i<m;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        cin>>r;
        sort(a.begin(),a.end());
        sort(r.begin(),r.end());
        int i=0;
        int k=0;
        while(i<m){
            s[a[i]-1]=r[k];
            i+=mp[a[i]];
            k++;
        }
        cout<<s<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}