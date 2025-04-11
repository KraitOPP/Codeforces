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
        if(n%2==0) cout<<-1<<endl;
        else{
            vector<int> res(n);
            int x=1;
            for(int i=0;i<n/2;i++){
                res[i]=x;
                res[n-1-i]=x+1;
                x+=2;
            }
            res[n/2]=n;
            for(int i=0;i<n;i++) cout<<res[i]<<" ";
            cout<<endl;
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}