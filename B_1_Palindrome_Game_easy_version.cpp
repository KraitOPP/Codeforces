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
        string s;
        cin>>n>>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt++;
        }
        if(cnt==n) cout<<"DRAW"<<endl;
        else if(n%2==0 || (n%2==1 && s[n/2]=='1') || (s[n/2]=='0' && (n-cnt)==1)) cout<<"BOB"<<endl;
        else cout<<"ALICE"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}