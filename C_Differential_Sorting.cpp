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
        for(int i=0;i<n;i++) cin>>a[i];
        if(a[n-2]>a[n-1]) cout<<-1<<endl;
        else{
            bool flag=true;
            if(a[n-1]<0){
                for(int i=1;i<n;i++){
                    if(a[i]<a[i-1]){
                        flag=false;
                        break;
                    }
                }
                if(flag) cout<<0<<endl;
                else cout<<-1<<endl;
            }
            else{
                cout<<n-2<<endl;
                for(int i=1;i<=n-2;i++){
                    cout<<i<<" "<<n-1<<" "<<n<<endl;
                }
            }
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}