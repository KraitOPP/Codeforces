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
        int n,x,y;
        cin>>n>>x>>y;
        int lc = (x*y)/(__gcd(x,y));
        x=n/x,y=n/y;
        int a = x-n/lc,b=y-n/lc;
        int s1 = n*(n+1)/2 - (n-a)*(n-a+1)/2;
        int s2 = b*(b+1)/2;
        cout<<s1-s2<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}