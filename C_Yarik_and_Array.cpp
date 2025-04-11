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
        for(int i=0;i<n;i++) cin>>a[i];
        int sum=a[0];
        int mxsum=a[0];
        int f=a[0]%2;
        for(int i=1;i<n;i++){
            if(abs(a[i]%2)==0 && f!=0){
                if(sum<0) sum=a[i];
                else sum+=a[i];
                f=0;
            }
            else if(abs(a[i]%2)==1 && f!=1){
                if(sum<0) sum=a[i];
                else sum+=a[i];
                f=1;
            }
            else{
                sum = a[i];
                f=a[i]%2;
            }
            mxsum=max(mxsum,sum);
        }
        cout<<mxsum<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}