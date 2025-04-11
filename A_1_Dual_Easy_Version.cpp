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
        int cnt=0, cnt2=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>0) cnt++;
            else if(a[i]<0) cnt2++;
        }
        if(cnt==n){
            cout<<n-1<<endl;
            for(int i=1;i<n;i++) cout<<i+1<<" "<<i<<endl;
        }
        else if(cnt2==n){
            cout<<n-1<<endl;
            for(int i=n-2;i>=0;i--) cout<<i+1<<" "<<i+2<<endl;
        }
        else if(cnt==0 && cnt2==0) cout<<0<<endl;
        else{

            int mx=0,idx;
            for(int i=0;i<n;i++){
                if(a[i]>mx){
                    mx=a[i];
                    idx=i;
                }
            }
            cout<<2*n+3<<endl;
            for(int i=0;i<5;i++) cout<<idx+1<<" "<<idx+1<<endl;
            for(int i=1;i<n;i++){
                cout<<i+1<<" "<<i<<endl;
                cout<<i+1<<" "<<i<<endl;
            }

        }



        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}