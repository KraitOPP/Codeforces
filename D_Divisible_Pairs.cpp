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
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> a(n);
        map<int,map<int,int>> mp;
        int res=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            int cx = x - a[i]%x,cy=a[i]%y;
            if(cx==x) cx=0;
            res+=mp[cx][cy];
            mp[a[i]%x][cy]++;
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}