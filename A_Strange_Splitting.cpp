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
        vector<int> a(n);
        map<int,int> mp;
        int cnt=0;
        loop(i,0,n){
            cin>>a[i];
            if(mp[a[i]]==0) cnt++;
            mp[a[i]]++;
        }
        if(cnt==1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            if(cnt==2){
                if(mp[a[0]]==1){
                    for(int i=0;i<n-1;i++) cout<<"B";
                    cout<<"R"<<endl;
                }
                else{
                    cout<<"B";
                    for(int i=0;i<n-1;i++) cout<<"R";
                    cout<<endl;
                }
            }
            else{
                cout<<"B";
                for(int i=1;i<n;i++) cout<<"R";
                cout<<endl;
            }
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}