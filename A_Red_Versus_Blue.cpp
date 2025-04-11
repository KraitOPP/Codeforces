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
        int n,r,b;
        cin>>n>>r>>b;
        string ans;
        int mx = r/(b+1);
        int rem = r%(b+1);
        int cnt=1;
        while(cnt<=n){
            ans+=string(mx,'R');
            cnt+=mx;
            if(rem){
                ans+='R';
                rem--;
                cnt++;
            }
            if(cnt<=n){
                ans+='B';
                cnt++;
            }
        }

        cout<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}