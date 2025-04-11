#include <bits/stdc++.h>
using namespace std;

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<long long> x(n+1);
        vector<long long> y(n+1);
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
        long long price = abs(x[a]-x[b])+abs(y[a]-y[b]);
        long long prmaj1=LONG_LONG_MAX/2;
        long long prmaj2=LONG_LONG_MAX/2;
        for(long long i=1;i<=k;i++){
            prmaj1=min(prmaj1,abs(x[a]-x[i])+abs(y[a]-y[i]));
            prmaj2=min(prmaj2,abs(x[b]-x[i])+abs(y[b]-y[i]));
        }
        cout<<min(price,prmaj1+prmaj2)<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}