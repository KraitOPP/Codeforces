#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int,bool> mp;
    for(int i=2;i<=1000;i++){
        int sum=1+i;
        int x=i*i;
        while(sum<=1000000){
            sum+=x;
            mp[sum]=true;
            x*=i;
        }
    }
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        int k=2;
    
        if(mp[n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}