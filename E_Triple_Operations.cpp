#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> a(2000001,0);
    vector<int> pre(2000001,0);
    int cnt=1;

    for(int i=1;i<=200000;i*=3){
        for(int j=i;j<3*i;j++){
            a[j] = cnt;
        }
        cnt++;
    }

    for(int i=1;i<=200000;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int l,r;
        cin>>l>>r;
        int res=pre[r]-pre[l-1];
        res+=a[l];
        cout<<res<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}