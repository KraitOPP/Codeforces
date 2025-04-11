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
        int g1=0,g2=0;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i%2==0) g1=__gcd(g1,a[i]);
            else g2=__gcd(g2,a[i]);
        }
        if(g1!=g2){
            bool f1=true,f2=true;
            for(int i=1;i<n;i+=2){
                if(a[i]%g1==0){
                    f1=false;
                    break;
                }
            }
            for(int i=0;i<n;i+=2){
                if(a[i]%g2==0){
                    f2=false;
                    break;
                }
            }
            if(f1) cout<<g1<<endl;
            else if(f2) cout<<g2<<endl;
            else cout<<0<<endl;
        }
        else cout<<0<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}