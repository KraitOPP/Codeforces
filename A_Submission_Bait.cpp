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
        vector<int> a(n),cnt(51,0);
        int flag=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        for(int i=50;i>=0;i--){
            if(cnt[i]%2==1){
                flag=1;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}