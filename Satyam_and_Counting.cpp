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
        vector<int> a0, a1;
        set<int> m0, m1;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(y==0){
                a0.push_back(x);
                m0.insert(x);
            }
            else{
                a1.push_back(x);
                m1.insert(x);
            }
        }
        int ans=0;
        sort(a0.begin(),a0.end());
        sort(a1.begin(),a1.end());
       
        for(int i=0;i<a0.size();i++){
            if(m0.find(a0[i]+2)!=m0.end() && m1.find(a0[i]+1)!=m1.end()) ans++;
        }
        for(int i=0;i<a1.size();i++){
            if(m1.find(a1[i]+2)!=m1.end() && m0.find(a1[i]+1)!=m0.end()) ans++;
        }

        int sm=0;
        for(int i=0;i<=n;i++){
            bool f0=true,f1=true;
            if(m0.find(i)==m0.end()) f0=false;
            if(m1.find(i)==m1.end()) f1=false;
            if(f0 && f1) sm++;
        }

        ans+=sm*(n-2);


        cout << ans << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}
