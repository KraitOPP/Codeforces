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
        vector<int> a(n);
        int idx=0,idx1=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==n) idx=i;
            if(a[i]==n-1) idx1=i;
        }
        int rq;
        if(idx==0) rq=idx1;
        else rq=idx;
        if(rq==n-1){
            int tmp=rq;
            while(tmp-1>=0 && a[tmp-1]>=a[0]){
                tmp--;
            }
            for(int i=n-1;i>=tmp;i--) cout<<a[i]<<" ";
            for(int i=0;i<tmp;i++) cout<<a[i]<<" ";
            cout<<endl;
        }
        else{
            int tmp=rq-1;
            while(tmp-1>=0 && a[tmp-1]>=a[0]){
                tmp--;
            }
            for(int i=rq;i<n;i++) cout<<a[i]<<" ";
            for(int i=rq-1;i>=tmp;i--) cout<<a[i]<<" ";
            for(int i=0;i<tmp;i++) cout<<a[i]<<" ";
            cout<<endl;

        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}