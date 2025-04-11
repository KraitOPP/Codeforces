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
        int n,k;
        cin>>n>>k;
        int odd = (n%2==1 ? n/2+1 : n/2) - (n/k)*(k/2+1);
        int eve = n/2 - (n/k)*(k/2);
        if(k%2==0 || (odd>=0 && eve>=0 && odd<=(k/2+1) && eve<=(k/2)) ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}